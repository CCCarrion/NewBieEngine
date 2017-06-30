#include "../Head/CommandListManager.h"

NBE_NS_Render_START
CommanQueue::CommanQueue(D3D12_COMMAND_LIST_TYPE)
{

}

CommanQueue::~CommanQueue()
{
}

void CommanQueue::Create(ID3D12Device *)
{

}


CommandListManager::CommandListManager(ID3D12Device* pDevice,GPU_MemoryManager_DX12 * pGpuMemoryManager): 
m_graphicQueue(D3D12_COMMAND_LIST_TYPE_DIRECT),
m_computeQueue(D3D12_COMMAND_LIST_TYPE_COMPUTE),
m_copyQueue(D3D12_COMMAND_LIST_TYPE_COPY)
{
    m_pGpuMemoryManager = pGpuMemoryManager;

    m_graphicQueue.Create(pDevice);
    m_computeQueue.Create(pDevice);
    m_copyQueue.Create(pDevice);

}

CommandListManager::~CommandListManager()
{

}


NBE_NS_Render_END


