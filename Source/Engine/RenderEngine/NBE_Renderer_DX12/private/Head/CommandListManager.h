#ifndef __CommandListManager_h__
#define __CommandListManager_h__

#include "Config/Config.h"
#include "Util/public/SmartPointer.h"
#include "GPU_MemoryManager_DX12.h"
#include "d3d12.h"

NBE_NS_Render_START

class CommanQueue
{
public:
    CommanQueue(D3D12_COMMAND_LIST_TYPE);
    ~CommanQueue();
    void Create(ID3D12Device*);

private:

};

class CommandListManager
{

public:     
    CommandListManager(ID3D12Device*,GPU_MemoryManager_DX12*);
    ~CommandListManager();

public:

private:
    GPU_MemoryManager_DX12* m_pGpuMemoryManager;
    CommanQueue m_graphicQueue;
    CommanQueue m_computeQueue;
    CommanQueue m_copyQueue;
    //Bundle Queue?

};
NBE_Ptr_Typedef(CommandListManager)


NBE_NS_Render_END
#endif