#ifndef __Config_h__
#define __Config_h__

/**    Confirm  Platform      **/
#if defined(_WIN64) || defined(_WIN32)
	#define NBE_OS_WIN
#endif // OS

/**    Include Platform Macro File      **/
#ifdef NBE_OS_WIN
#include "Engine/xPlatform/NBE_OS_Windows/public/NBE_Macro_Windows.h"
#define OS_HEAD "Engine/xPlatform/NBE_OS_Windows/public/NBE_OS_Windows.h"
#endif // NBE_OS_WIN

/**    Define Interface Attribute  Temp **/
#pragma region DLL_IMPLEMENT(DLL_name)
/*
#undef NBE_API
#if defined(DLL_BUILD) && defined(DLL_name)	   
#define NBE_API DLLEXPORT					
#else											
#define NBE_API DLLIMPORT					
#endif
*/
#pragma endregion 
/**    ifndef def end  Temp **/
#pragma region (headTemp)
//#ifndef __XXX_h__
//#define __XXX_h__
//
//#endif
#pragma endregion
/**    Module Create Func   **/
#define NBE_LIB_CREATE_UPtr_DECLARE(InterfaceClass)   \
extern "C" void Create##InterfaceClassUPtr(InterfaceClass##_UPtr& uptr) ;

#define NBE_DLL_CREATE_UPtr_DECLARE(InterfaceClass)   \
extern "C" NBE_API void Create##InterfaceClassUPtr(InterfaceClass##_UPtr& uptr) ;

#define NBE_CREATE_UPtr_IMPLEMENT_FUNC_NAME(InterfaceClass,ImpClass)          \
extern "C" void Create##InterfaceClassUPtr(InterfaceClass##_UPtr& uptr)       

#define NBE_CREATE_UPtr_IMPLEMENT(InterfaceClass,ImpClass)                    \
NBE_CREATE_UPtr_IMPLEMENT_FUNC_NAME(InterfaceClass,ImpClass)                  \
{                                                                             \
     uptr = NBE_MakeUniquePtr<##ImpClass##>();                                \
}

#define NBE_CREATE_UPtr(InterfaceClass,UptrVal)   \
Create##InterfaceClassUPtr(UptrVal)



/**    Define NBE NameSpace   **/
#define NBE_NS_COMMON namespace NBE
#define NBE_NS_OS namespace NBE::OS
#define NBE_NS_Core namespace NBE::Core
#define NBE_NS_Render namespace NBE::Render

#define NBE_NS_COMMON_START namespace NBE {
#define NBE_NS_COMMON_END }
#define _NBE_NS_COMMON NBE::
#define NBE_NS_OS_START NBE_NS_COMMON_START namespace OS{
#define NBE_NS_OS_END NBE_NS_COMMON_END }
#define _NBE_NS_OS NBE::OS::
#define NBE_NS_Core_START NBE_NS_COMMON_START namespace Core{
#define NBE_NS_Core_END NBE_NS_COMMON_END }
#define _NBE_NS_Core NBE::Core::
#define NBE_NS_Render_START NBE_NS_COMMON_START namespace Render{
#define NBE_NS_Render_END NBE_NS_COMMON_END }
#define _NBE_NS_Render NBE::Render::

NBE_NS_COMMON{}
NBE_NS_OS{}
NBE_NS_Core{}
NBE_NS_Render{}

/**    Other config   **/
#include "NBE_ERROR_Def.h"
#include "NBE_Struct_Def.h"

#endif