#ifndef __NBE_OS_Windows_h__
#define __NBE_OS_Windows_h__

#include "Engine/Tools/Config/Config.h"
#include "Engine/xPlatform/Interface/NBE_Interface_OS.h"

#pragma region LIB_IMPLEMENT(NBE_OS_WIN_IMP)

#undef NBE_API
#if defined(LIB_BUILD) && defined(NBE_OS_WIN_IMP)
#define NBE_API DLLEXPORT
#else
#define NBE_API DLLIMPORT
#endif

#pragma endregion


namespace NBE::OS
{
	class NBE_API OS_APP_Windows : public OS_APP_Interface
	{
	public :
		OS_APP_Windows();
		virtual ~OS_APP_Windows();
		void LoadConfig(NBE_Engine_Config*) override;
		type_NBE_ERR CreateApp() override;

	private:
		NBE_Engine_Config* m_g_pCfg;
	};
}




#endif
