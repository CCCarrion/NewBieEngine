#ifndef __Render_Engine_DX12_h__
#define __Render_Engine_DX12_h__

#include "Config/Config.h"
#include "Engine/RenderEngine/Interface/NBE_Interface_Renderer.h"

#include "d3d12.h"
#include "dxgi1_4.h"
#include "wrl/client.h"

#pragma comment(lib,"d3d12.lib")
#pragma comment(lib,"dxgi.lib")


NBE_NS_Render_START
using Microsoft::WRL::ComPtr;

class Render_Engine_DX12 : public Render_Engine_Interface
{
public :
    Render_Engine_DX12();
    virtual ~Render_Engine_DX12();

    const NBE_WString & GetRendererName() override;


private:
    type_NBE_ERR CreateDeviceInterface();
    void CheckAdapterFeature();
private :
    ComPtr<ID3D12Device> m_device;

};
NBE_NS_Render_END



#endif