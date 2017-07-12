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

enum NBE_Texture_Format
{

};

//GPU Resource Interface
class NBE_API GPU_Resource_Interface
{
public :

    virtual ~GPU_Resource_Interface() = 0 {};
    virtual type_NBE_ERR Create();

};
NBE_Ptr_Typedef(GPU_Resource_Interface)

//GPU Memory Manager
class NBE_API GPU_MemoryManager_Interface
{
public :
    virtual ~GPU_MemoryManager_Interface() = 0 {};

};

NBE_Ptr_Typedef(GPU_MemoryManager_Interface)



//Render Engine Entity
class NBE_API Render_Engine_Interface
{
public :
    virtual ~Render_Engine_Interface() = 0 {};

    virtual const NBE_WString& GetRendererName() = 0;
    virtual type_NBE_ERR CreateRenderEngine(NBE_Engine_Config&, _NBE_NS_OS OS_APP_Interface*) = 0;


public :
    NBE_Adapter_Features_Support m_featureSupport;
    GPU_MemoryManager_Interface_UPtr m_gpuMemoryManager;
};

NBE_Ptr_Typedef(Render_Engine_Interface)





NBE_NS_Render_END

#endif