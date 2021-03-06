#include "NBEngine.h"


namespace NBE
{
	NBE_Entity::NBE_Entity():m_cfg(),m_pApp(nullptr)
	{
        
        NBE_CREATE_UPtr(OS_APP_Interface,m_pApp);
        LoadCfg();
        m_pApp->CreateApp(m_cfg);

        NBE_CREATE(Render_Engine_Interface, m_pRenderer);

	}

	void NBE_Entity::Run()
	{
        m_pApp->ShowCanvas();
        while (1)
        {
            m_pApp->Tick();
        }
	}

	NBE_Entity::~NBE_Entity()
	{

	}

    type_NBE_ERR NBE_Entity::LoadCfg()
    {
        //todo :use os to read file get config data  

        m_cfg.appName = NBE_WString(L"NewBie Engine");
        m_cfg.height = 720;
        m_cfg.width = 1080;
        m_cfg.renderEngineName = NBE_WString(NBE_Render_Engine_Name_DX12);

    }

}