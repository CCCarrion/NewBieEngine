#ifndef __NBE_Interface_OS_h__
#define __NBE_Interface_OS_h__

#include <Engine/Tools/Config/Config.h>

namespace NBE::OS
{

	class OS_APP_Interface
	{
	public:
		virtual ~OS_APP_Interface()=0 {};
		virtual type_NBE_ERR CreateApp(const NBE_Engine_Config&) = 0;

	private:
		
	};

}

#endif