#ifndef __CommandListManager_h__
#define __CommandListManager_h__

#include "Config/Config.h"
#include "Util/public/SmartPointer.h"
#include "GPU_MemoryManager_DX12.h"
#include "d3d12.h"

#include "wrl/client.h"

NBE_NS_Render_START

using Microsoft::WRL::ComPtr;

class CommandQueue
{
public:
    CommandQueue(D3D12_COMMAND_LIST_TYPE);
    ~CommandQueue();
    void Create(ID3D12Device*);
    ID3D12CommandQueue* GetCommandQueue();
private:
    const D3D12_COMMAND_LIST_TYPE m_type;
    ComPtr<ID3D12CommandQueue> m_pCommandQueue;
};

class CommandListManager
{

public:     
    CommandListManager(ID3D12Device*,GPU_MemoryManager_DX12*);
    ~CommandListManager();

    ID3D12CommandQueue* GetGraphicQueue();
public:

private:
    GPU_MemoryManager_DX12* m_pGpuMemoryManager;
    CommandQueue m_graphicQueue;
    CommandQueue m_computeQueue;
    CommandQueue m_copyQueue;
    //Bundle Queue?

};
NBE_Ptr_Typedef(CommandListManager)


NBE_NS_Render_END
#endif