#ifndef __NBE_OS_Windows_h__
#define __NBE_OS_Windows_h__

#include "Engine/Tools/Config/Config.h"

#pragma region LIB_IMPLEMENT(NBE_OS_WIN_IMP)

#undef NBE_API
#if defined(LIB_BUILD) && defined(NBE_OS_WIN_IMP)
#define NBE_API DLLEXPORT
#else
#define NBE_API DLLIMPORT
#endif

#pragma endregion


NBE_NS_OS
{

}




#endif
