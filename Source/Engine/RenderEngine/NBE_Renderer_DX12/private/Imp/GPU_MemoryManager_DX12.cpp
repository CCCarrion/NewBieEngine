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

    return NBE_OK;
}

type_NBE_ERR GPU_Resource_DX12::Create(ID3D12Resource* pRes)
{
    if (pRes == nullptr) {
       return NBE_ERROR_RENDER_BASE_RESOURCE_IS_NULL;
    }
    D3D12_RESOURCE_DESC ResourceDesc = pRes->GetDesc();
    m_pRes.Attach(pRes);
    m_width = (NBE_type_size)ResourceDesc.Width;
    m_height = (NBE_type_size)ResourceDesc.Height;
    m_depth = (NBE_type_size)ResourceDesc.DepthOrArraySize;
    
    m_format = ConvertFormat(ResourceDesc.Format);
    m_currentState = NBE_RESOURCE_STATE_NORMAL;

    return NBE_OK;
}

GPU_MemoryManager_DX12::GPU_MemoryManager_DX12()
{

}

GPU_MemoryManager_DX12::~GPU_MemoryManager_DX12()
{

}


NBE_NS_Render_END

