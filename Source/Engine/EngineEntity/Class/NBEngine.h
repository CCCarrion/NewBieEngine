#ifndef __NBEngine_h__
#define __NBEngine_h__
#include "Engine/Tools/Config/Config.h"
#include OS_HEAD
#include "Engine/Tools/Util/public/SmartPointer.h"
#include "Engine/RenderEngine/Interface/NBE_Interface_Renderer.h"

namespace NBE
{
	using NBE_NS_OS;
    using NBE_NS_Render;
	class NBE_Entity
	{
	public: 
		NBE_Entity();		//Create Instance 
		void Run();			//Runtime
		~NBE_Entity();		//Quit

    protected:
        type_NBE_ERR LoadCfg();
	protected:
        NBE_Engine_Config m_cfg;
        OS_APP_Interface_UPtr m_pApp;
        Render_Engine_Interface_UPtr m_pRenderer;
	};
}

#endif // __NBEngine_h__

