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
    friend class GPU_MemoryManager_DX12;
    GPU_Resource_DX12();
    ~GPU_Resource_DX12() override;
    type_NBE_ERR Create() override;
    type_NBE_ERR Attach(ID3D12Resource*,NBE_Resource_Type);
   // void SetProperty(NBE_type_size width, NBE_type_size height, NBE_type_size depth, NBE_Resource_Format pixFormat, NBE_Resource_Layout layout = NBE_RESOURCE_LAYOUT_UNKNOWN, NBE_Resource_Type type = NBE_RESOURCE_TYPE_UNKNOWN) override;

private :
    ComPtr<ID3D12Resource> m_pRes;
    
};
NBE_Ptr_Typedef(GPU_Resource_DX12)


class GPU_MemoryManager_DX12 : public GPU_MemoryManager_Interface
{
public :
    GPU_MemoryManager_DX12();
    ~GPU_MemoryManager_DX12() override;
    GPU_Resource_Interface* CreateGPUResource(NBE_Resource_Descriptor*, NBE_Pixel_Value*) override;

private:

};



//Convert D3D12 Format to Engine Defined Format
inline NBE_Resource_Format ConvertFormat(DXGI_FORMAT format)
{
    switch (format)
    {
    case NBE_RESOURCE_FORMAT_D24S8:
        return DXGI_FORMAT_D24_UNORM_S8_UINT;
        break;
        

    }
    
    return NBE_RESOURCE_FORMAT_UNKNOWN;
}
inline DXGI_FORMAT ConvertFormat(NBE_Resource_Format format)
{
    switch (format)
    {
    case DXGI_FORMAT_D24_UNORM_S8_UINT:
            return NBE_RESOURCE_FORMAT_D24S8;
            break;
       

    }


    return DXGI_FORMAT_UNKNOWN;
}



NBE_NS_Render_END
#endif