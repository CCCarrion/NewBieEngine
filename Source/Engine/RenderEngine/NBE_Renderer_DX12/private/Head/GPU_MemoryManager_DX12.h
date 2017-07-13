#ifndef __GPU_MemoryManager_DX12_h__
#define __GPU_MemoryManager_DX12_h__

#include "Config/Config.h"
#include "Engine/RenderEngine/Interface/NBE_Interface_Renderer.h"
#include "Render_Engine_DX12.h"
NBE_NS_Render_START

extern Render_Engine_DX12* g_pRenderEngine;

class GPU_Resource_DX12 :public GPU_Resource_Interface
{
public:
    GPU_Resource_DX12();
    ~GPU_Resource_DX12() override;
    type_NBE_ERR Create() override;
    type_NBE_ERR Create(ID3D12Resource*);

private :
    ComPtr<ID3D12Resource> m_pRes;
    
};


class GPU_MemoryManager_DX12 : public GPU_MemoryManager_Interface
{
public :
    GPU_MemoryManager_DX12();
    ~GPU_MemoryManager_DX12() override;


private:

};

//Convert D3D12 Format to Engine Defined Format
inline NBE_Texture_Format ConvertFormat(DXGI_FORMAT format)
{
    switch (format)
    {
     
        

    }

    return NBE_TEXTURE_FORMAT_UNKNOWN;
}

NBE_NS_Render_END
#endif