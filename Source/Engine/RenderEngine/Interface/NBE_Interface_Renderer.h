#ifndef __NBE_Interface_Renderer_h__
#define __NBE_Interface_Renderer_h__

#include "Config/Config.h"
#include "Util/public/SmartPointer.h"

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

struct NBE_Adapter_Features_Support
{

};



class NBE_API Render_Engine_Interface
{
public :
    virtual ~Render_Engine_Interface() = 0 {};

    virtual const NBE_WString& GetRendererName() = 0;

public :
    NBE_Adapter_Features_Support m_featureSupport;
};

NBE_Ptr_Typedef(Render_Engine_Interface)




NBE_NS_Render_END

#endif