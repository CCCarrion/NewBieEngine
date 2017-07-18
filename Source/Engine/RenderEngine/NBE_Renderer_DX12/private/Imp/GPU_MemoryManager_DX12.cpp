#include "../Head/GPU_MemoryManager_DX12.h"
NBE_NS_Render_START
GPU_Resource_DX12::GPU_Resource_DX12()
{


}





GPU_Resource_DX12::~GPU_Resource_DX12()
{

}

type_NBE_ERR GPU_Resource_DX12::Create()
{
    if (m_pRes.Get() != nullptr)
    {
        m_pRes.Detach();
        //TODO : Log a resource instance have create res twice

    }
    D3D12_RESOURCE_DESC desc = {};
    desc.Dimension = D3D12_RESOURCE_DIMENSION_TEXTURE2D;
    desc.Alignment = 0;
    desc.Width = static_cast<UINT>(m_width);
    desc.Height = static_cast<UINT>(m_height);
    desc.DepthOrArraySize = static_cast<UINT>(m_depth);
    desc.MipLevels = 1;
    desc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
    desc.SampleDesc.Count = 1;
    desc.SampleDesc.Quality = 0;
    desc.Layout = D3D12_TEXTURE_LAYOUT_UNKNOWN;
    desc.Flags = D3D12_RESOURCE_FLAG_ALLOW_DEPTH_STENCIL | D3D12_RESOURCE_FLAG_DENY_SHADER_RESOURCE;


    return NBE_OK;
}

type_NBE_ERR GPU_Resource_DX12::Attach(ID3D12Resource* pRes,NBE_Resource_Type type)
{
    if (pRes == nullptr) {
       return NBE_ERROR_RENDER_BASE_RESOURCE_IS_NULL;
    }

    D3D12_RESOURCE_DESC ResourceDesc = pRes->GetDesc();
    m_pRes.Attach(pRes);
    m_desc.texDesc.width = (NBE_type_size)ResourceDesc.Width;
    m_desc.texDesc.height = (NBE_type_size)ResourceDesc.Height;
    m_desc.texDesc.depth = (NBE_type_size)ResourceDesc.DepthOrArraySize;
    
    m_desc.texDesc.format = ConvertFormat(ResourceDesc.Format);
    m_desc.resType = type;
    m_state = NBE_RESOURCE_STATE_NORMAL;

    return NBE_OK;
}

//void GPU_Resource_DX12::SetProperty(NBE_type_size width, NBE_type_size height, NBE_type_size depth, NBE_Resource_Format pixFormat, NBE_Resource_Layout layout, NBE_Resource_Type type)
//{
//    m_width = width;
//    m_height = height;
//    m_depth = depth;
//
//    m_format = pixFormat;
//    m_layout = layout;
//    m_resType = type;
//}

GPU_MemoryManager_DX12::GPU_MemoryManager_DX12()
{

}

GPU_MemoryManager_DX12::~GPU_MemoryManager_DX12()
{

}

//Just Need Resource Info and Allocate a Block GPU Memory
GPU_Resource_Interface * GPU_MemoryManager_DX12::CreateGPUResource(NBE_Resource_Descriptor * resDesc, NBE_Pixel_Value* initValue)
{
    GPU_Resource_DX12* pGPURes = new GPU_Resource_DX12();
    ID3D12Device *pDevice = g_pRenderEngine->GetDevice();
    ID3D12Resource * pRes;

    DXGI_FORMAT dx12Format = ConvertFormat(resDesc->texDesc.format);
   
    D3D12_CLEAR_VALUE clearValue;
    if (initValue != nullptr) {
        clearValue.Format = ConvertFormat(initValue->format);
        clearValue.DepthStencil.Depth = initValue->DS_Value.depth;
        clearValue.DepthStencil.Stencil = initValue->DS_Value.stencil;
    }

    D3D12_RESOURCE_DESC desc = {};

    switch (resDesc->resType)
    {
    case NBE_RESOURCE_TYPE_DS:
        desc.Dimension = D3D12_RESOURCE_DIMENSION_TEXTURE2D;
        desc.Alignment = 0;
        desc.Width = static_cast<UINT>(resDesc->texDesc.width);
        desc.Height = static_cast<UINT>(resDesc->texDesc.height);
        desc.DepthOrArraySize = static_cast<UINT>(resDesc->texDesc.depth);
        desc.MipLevels = 1;
        desc.Format = dx12Format;
        desc.SampleDesc.Count = 1;
        desc.SampleDesc.Quality = 0;
        desc.Layout = D3D12_TEXTURE_LAYOUT_UNKNOWN;
        desc.Flags = D3D12_RESOURCE_FLAG_ALLOW_DEPTH_STENCIL | D3D12_RESOURCE_FLAG_DENY_SHADER_RESOURCE;

        D3D12_HEAP_PROPERTIES heapProp = {};
        heapProp.Type = D3D12_HEAP_TYPE_DEFAULT;
        heapProp.CPUPageProperty = D3D12_CPU_PAGE_PROPERTY_UNKNOWN;
        heapProp.MemoryPoolPreference = D3D12_MEMORY_POOL_UNKNOWN;
        heapProp.CreationNodeMask = 1;
        heapProp.VisibleNodeMask = 1;

        ThrowIfFailed(pDevice->CreateCommittedResource(&heapProp, D3D12_HEAP_FLAG_NONE, &desc, D3D12_RESOURCE_STATE_DEPTH_WRITE, &clearValue, IID_PPV_ARGS(&pRes)));
        break;

    }
    pGPURes->m_pRes.Attach(pRes);
    pGPURes->m_desc = *resDesc;
    pGPURes->m_state = NBE_RESOURCE_STATE_NORMAL;

    return pGPURes;
}


NBE_NS_Render_END

