#ifndef __Config_h__
#define __Config_h__

/**    Confirm  Platform      **/
#if defined(_WIN64) || defined(_WIN32)
	#define NBE_OS_WIN
#endif // OS

/**    Include Platform Macro File      **/
#ifdef NBE_OS_WIN
#include "Engine/xPlatform/NBE_OS_Windows/public/NBE_Macro_Windows.h"
#endif // NBE_OS_WIN

/**    Define Interface Attribute  Temp **/
#pragma region LIB_IMPLEMENT(lib_name)
/*
#if defined(LIB_BUILD) && defined(lib_name)	   
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


/**    Define NBE NameSpace   **/
#define NBE_NS_COMMON namespace NBE
#define NBE_NS_OS namespace NBE::OS
#define NBE_NS_Core namespace NBE::Core
NBE_NS_COMMON{}
NBE_NS_OS{}
NBE_NS_Core{}

 

/**    Other config   **/
#include "NBE_ERROR_Def.h"
#include "NBE_Struct_Def.h"

#endif