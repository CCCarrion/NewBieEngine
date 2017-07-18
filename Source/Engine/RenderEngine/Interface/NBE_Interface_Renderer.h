#ifndef __NBE_Interface_Renderer_h__
#define __NBE_Interface_Renderer_h__

#include "Config/Config.h"
#include "Util/public/SmartPointer.h"
#include "Engine/xPlatform/Interface/NBE_Interface_OS.h"

#pragma region DLL_IMPLEMENT(NBE_RENDERER_IMP)
#undef NBE_API
#if defined(DLL_BUILD) && defined(NBE_RENDERER_IMP)
#define NBE_API DLLEXPORT
#else
#define NBE_API DLLIMPORT
#endif

#pragma endregion 

NBE_NS_Render_START

//define name 
#define NBE_Render_Engine_Name_DX12 L"DX12"
#define NBE_Render_Engine_Name_Vulkan L"Vulkan"

//Support Feature Struct
struct NBE_Adapter_Features_Support
{

};

enum NBE_Resource_Format
{
    NBE_RESOURCE_FORMAT_UNKNOWN = 0,
    NBE_RESOURCE_FORMAT_D24S8,//Depth 24 Stencil 8 


   
};

struct NBE_Pixel_Value
{
    NBE_Resource_Format format;

    union 
    {
        float Color[4] ;
        struct 
        {
            float depth ;
            UINT  stencil ;
        } DS_Value;
    };
};

enum NBE_Resource_Layout
{
    NBE_RESOURCE_LAYOUT_UNKNOWN = 0,
};

enum NBE_Resource_Type
{
    NBE_RESOURCE_TYPE_UNKNOWN = 0,
    NBE_RESOURCE_TYPE_RT,//Render Target
    NBE_RESOURCE_TYPE_DS,//DepthStencil Buffer
};

enum NBE_Resource_State
{
    NBE_RESOURCE_STATE_UNKNOWN = 0,
    NBE_RESOURCE_STATE_NORMAL,
    NBE_RESOURCE_STATE_RENDERING,
    NBE_RESOURCE_STATE_PRESENT
};

//Resource property
struct  NBE_Resource_Descriptor
{
    NBE_Resource_Type resType;

    union 
    {
        struct {
            NBE_type_size width;
            NBE_type_size height;
            NBE_type_size depth;
            NBE_Resource_Format format;
            NBE_Resource_Layout layout;
            NBE_type_size mipmap;
         } texDesc;
    };



    
};


//GPU Resource Interface
class NBE_API GPU_Resource_Interface
{
public :

    virtual ~GPU_Resource_Interface() = 0 {};
    virtual type_NBE_ERR Create();
    //virtual void SetProperty(NBE_type_size width,NBE_type_size height,NBE_type_size depth,NBE_Resource_Format pixFormat,NBE_Resource_Layout layout = NBE_RESOURCE_LAYOUT_UNKNOWN, NBE_Resource_Type type = NBE_RESOURCE_TYPE_UNKNOWN);
    virtual type_NBE_ERR UploadData(void*);

public :
    NBE_Resource_Descriptor m_desc;
    NBE_Resource_State m_state;
};
NBE_Ptr_Typedef(GPU_Resource_Interface)

//GPU Memory Manager
class NBE_API GPU_MemoryManager_Interface
{
public:
    virtual ~GPU_MemoryManager_Interface() = 0 {};

    virtual GPU_Resource_Interface* CreateGPUResource(NBE_Resource_Descriptor*, NBE_Pixel_Value* pixValue);    //create a buffer filled with given value




};

NBE_Ptr_Typedef(GPU_MemoryManager_Interface)



//Render Engine Entity
class NBE_API Render_Engine_Interface
{
public :
    virtual ~Render_Engine_Interface() = 0 {};

    virtual const NBE_WString& GetRendererName() = 0;
    virtual type_NBE_ERR CreateRenderEngine(NBE_Engine_Config&, _NBE_NS_OS OS_APP_Interface*) = 0;

    //virtual type_NBE_ERR PrepareRender();

    //virtual type_NBE_ERR AfterRender();

    GPU_MemoryManager_Interface* GetGPUResourceManager() { return m_gpuMemoryManager.get(); };
    virtual GPU_Resource_Interface* GetFrameBuffer(NBE_type_size);
    virtual GPU_Resource_Interface* GetDSBuffer(NBE_type_size);

public :
    NBE_Adapter_Features_Support m_featureSupport;
    GPU_MemoryManager_Interface_UPtr m_gpuMemoryManager;
    NBE_type_size m_nTotalFrame;

protected :
    NBE_type_size m_nFrameIndex;

    

};

NBE_Ptr_Typedef(Render_Engine_Interface)





NBE_NS_Render_END

#endif