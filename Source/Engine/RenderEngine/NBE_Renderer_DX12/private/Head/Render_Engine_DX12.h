#ifndef __Render_Engine_DX12_h__
#define __Render_Engine_DX12_h__

#include "Config/Config.h"
#include "Engine/RenderEngine/Interface/NBE_Interface_Renderer.h"
#include "Util/public/Container.h"

#include <windows.h>
#include "d3d12.h"
#include "dxgi1_4.h"
#include "wrl/client.h"

#pragma comment(lib,"d3d12.lib")
#pragma comment(lib,"dxgi.lib")

#include "CommandListManager.h"


NBE_NS_Render_START
using Microsoft::WRL::ComPtr;

class Render_Engine_DX12 : public Render_Engine_Interface
{
public :        //Interface Func
    Render_Engine_DX12();
    virtual ~Render_Engine_DX12();

    const NBE_WString & GetRendererName() override;
    type_NBE_ERR CreateRenderEngine(NBE_Engine_Config&, _NBE_NS_OS OS_APP_Interface*) override;

    GPU_Resource_Interface* GetFrameBuffer(NBE_type_size) override;
    GPU_Resource_Interface* GetDSBuffer(NBE_type_size) override;

public:       
    inline ID3D12Device* GetDevice() { return m_device.Get(); };

private:
    void CheckAdapterFeature();
    void Present();

private :
    ComPtr<ID3D12Device> m_device;
    CommandListManager_UPtr m_cmdListManager;
    ComPtr<IDXGISwapChain1> m_swapChain;
    NBE_Vector<GPU_Resource_DX12_UPtr> m_listSwapChainRes;
    GPU_Resource_DX12_UPtr m_depthStencilRes;

};
NBE_NS_Render_END



#endif