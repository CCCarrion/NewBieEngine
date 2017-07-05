#include "../Head/CommandListManager.h"

NBE_NS_Render_START
CommandQueue::CommandQueue(D3D12_COMMAND_LIST_TYPE type):
    m_type(type)
{

}

CommandQueue::~CommandQueue()
{
}

void CommandQueue::Create(ID3D12Device * pDevice)
{
    D3D12_COMMAND_QUEUE_DESC QueueDesc = {};
    QueueDesc.Type = m_type;
    QueueDesc.NodeMask = 1;
    pDevice->CreateCommandQueue(&QueueDesc, IID_PPV_ARGS(&m_pCommandQueue));

}

ID3D12CommandQueue * CommandQueue::GetCommandQueue()
{
    return m_pCommandQueue.Get();
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

ID3D12CommandQueue * CommandListManager::GetGraphicQueue()
{
    return m_graphicQueue.GetCommandQueue();
}


NBE_NS_Render_END


