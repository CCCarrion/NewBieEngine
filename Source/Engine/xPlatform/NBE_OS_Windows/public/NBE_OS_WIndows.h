#ifndef __NBE_OS_Windows_h__
#define __NBE_OS_Windows_h__




#include "Engine/Tools/Config/Config.h"
#include "Engine/Tools/Util/public/SmartPointer.h"
#include "Engine/xPlatform/Interface/NBE_Interface_OS.h"

#include <windows.h>

NBE_NS_OS_START
	class OS_APP_Windows : public OS_APP_Interface
	{
	public :
		OS_APP_Windows();
		virtual ~OS_APP_Windows();
		type_NBE_ERR CreateApp(const NBE_Engine_Config&) override;
		type_NBE_ERR ShowCanvas() override;
		void Tick() override;

	private:
		HWND m_hwnd;
	};
NBE_NS_OS_END



#endif
