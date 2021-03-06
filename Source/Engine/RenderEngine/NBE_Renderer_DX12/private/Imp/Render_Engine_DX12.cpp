#include "../Head/Render_Engine_DX12.h"
#include "../Head/GPU_MemoryManager_DX12.h"




NBE_NS_Render_START

Render_Engine_DX12::Render_Engine_DX12()
{
    CheckAdapterFeature();

}

Render_Engine_DX12::~Render_Engine_DX12()
{

}

const NBE_WString& Render_Engine_DX12::GetRendererName()
{
    static NBE_WString const name(NBE_Render_Engine_Name_DX12);
    return name;
}


GPU_Resource_Interface * Render_Engine_DX12::GetFrameBuffer(NBE_type_size index)
{
    return m_listSwapChainRes[index].get();
}

GPU_Resource_Interface * Render_Engine_DX12::GetDSBuffer(NBE_type_size)
{
    return m_depthStencilRes.get();
}

type_NBE_ERR Render_Engine_DX12::CreateRenderEngine(NBE_Engine_Config & cfg, _NBE_NS_OS OS_APP_Interface* pApp)
{
    //Create Device
    UINT dxgiFactoryFlags = 0;
    ComPtr<IDXGIFactory4> factory;
    ThrowIfFailed(CreateDXGIFactory2(dxgiFactoryFlags, IID_PPV_ARGS(&factory)));

    UINT adapterOrder = 0;
    IDXGIAdapter1* adapter;

    //TODO : Need To Meet The Cfg and Select the Best One
    while (factory->EnumAdapters1(adapterOrder, &adapter) != DXGI_ERROR_NOT_FOUND)
    {
        if (m_device)
        {
            break;
        }

        DXGI_ADAPTER_DESC1 desc;
        adapter->GetDesc1(&desc);
        ++adapterOrder;

        if (SUCCEEDED(D3D12CreateDevice(adapter, D3D_FEATURE_LEVEL_11_0, IID_PPV_ARGS(&m_device))))
        {
            if (m_device)
            {
                m_device.Detach()->Release();
            }
        }
        adapter->Release();
    }

    if (!m_device)
    {
        return NBE_ERROR_DX12_NOT_SURPPORT;
    }

    //Check Feature Support
    CheckAdapterFeature();

    //Create GPU Memory Manager
    //TODO: Its Temp
    m_gpuMemoryManager = NBE_MakeUniquePtr<GPU_MemoryManager_DX12>();
    m_cmdListManager = NBE_MakeUniquePtr<CommandListManager>(m_device,m_gpuMemoryManager);


    //Create SwapChain
    DXGI_SWAP_CHAIN_DESC1 swapChainDesc = {};
    swapChainDesc.Width = cfg.width;
    swapChainDesc.Height = cfg.height;
    swapChainDesc.Format = DXGI_FORMAT_R10G10B10A2_UNORM;
    swapChainDesc.Scaling = DXGI_SCALING_NONE;
    swapChainDesc.SampleDesc.Quality = 0;
    swapChainDesc.SampleDesc.Count = 1;
    swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    swapChainDesc.BufferCount = cfg.swapChainCount;
    swapChainDesc.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
    swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL;
#ifdef NBE_OS_WIN
    ThrowIfFailed(factory->CreateSwapChainForHwnd(m_cmdListManager->GetGraphicQueue(), (HWND)pApp->GetAppHandle(), &swapChainDesc, nullptr, nullptr, &m_swapChain));
#endif // NBE_OS_WIN
    m_listSwapChainRes.resize(cfg.swapChainCount);
    for (uint32_t i = 0; i < cfg.swapChainCount; i++)
    {
        //Create Buffer Descriptor for swapChain
        ID3D12Resource* frameRes;
        ThrowIfFailed(m_swapChain->GetBuffer(i, IID_PPV_ARGS(&frameRes)));
        m_listSwapChainRes[i] = NBE_MakeSharedPtr<GPU_Resource_DX12>();
        m_listSwapChainRes[i]->Attach(frameRes,NBE_RESOURCE_TYPE_RT);
    }
    m_nFrameIndex = 0;

    NBE_Resource_Descriptor resDesc = {};
    resDesc.resType = NBE_RESOURCE_TYPE_DS;
    resDesc.texDesc.width = cfg.width;
    resDesc.texDesc.height = cfg.height;
    resDesc.texDesc.depth = 1;
    resDesc.texDesc.format = ConvertFormat(DXGI_FORMAT_D24_UNORM_S8_UINT);
    resDesc.texDesc.layout = NBE_RESOURCE_LAYOUT_UNKNOWN;
    
    NBE_Pixel_Value pixValue = {};
    pixValue.format = NBE_RESOURCE_FORMAT_D24S8;
    pixValue.DS_Value.depth = 1.0f;
    pixValue.DS_Value.stencil = 0;
    m_depthStencilRes.reset(g_pRenderEngine->GetGPUResourceManager()->CreateGPUResource(resDesc,pixValue));

    return NBE_OK;
}

//Check Feature Support
void Render_Engine_DX12::CheckAdapterFeature()
{
    D3D12_FEATURE_DATA_D3D12_OPTIONS FeatureData = {};
    if (SUCCEEDED(m_device->CheckFeatureSupport(D3D12_FEATURE_D3D12_OPTIONS, &FeatureData, sizeof(FeatureData))))
    {
        if (FeatureData.TypedUAVLoadAdditionalFormats)
        {
            D3D12_FEATURE_DATA_FORMAT_SUPPORT Support =
            {
                DXGI_FORMAT_R11G11B10_FLOAT, D3D12_FORMAT_SUPPORT1_NONE, D3D12_FORMAT_SUPPORT2_NONE
            };

            if (SUCCEEDED(m_device->CheckFeatureSupport(D3D12_FEATURE_FORMAT_SUPPORT, &Support, sizeof(Support))) &&
                (Support.Support2 & D3D12_FORMAT_SUPPORT2_UAV_TYPED_LOAD) != 0)
            {
               
            }
        }
    }
}

//After Render to Present Frame
void Render_Engine_DX12::Present()
{

}

NBE_NS_Render_END