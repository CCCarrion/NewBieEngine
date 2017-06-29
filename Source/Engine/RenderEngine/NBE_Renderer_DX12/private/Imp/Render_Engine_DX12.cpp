#include "../Head/Render_Engine_DX12.h"





NBE_NS_Render_START

Render_Engine_DX12::Render_Engine_DX12()
{
    ThrowIfFailed(CreateDeviceInterface());
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

type_NBE_ERR Render_Engine_DX12::CreateDeviceInterface()
{
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

NBE_NS_Render_END