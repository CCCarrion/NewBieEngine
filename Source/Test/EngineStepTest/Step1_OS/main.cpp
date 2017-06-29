
#include "Engine/Tools/Config/Config.h"
#include "Engine/xPlatform/Interface/NBE_Interface_OS.h"
#include "Engine/xPlatform/NBE_OS_Windows/public/NBE_OS_Windows.h"

#pragma comment(lib,"NBE_OS_Windows.lib")

void AppStart()
{
    using NBE_NS_OS;

    OS_APP_Interface_UPtr pApp;
    NBE_CREATE_UPtr(OS_APP_Interface,pApp);
    NBE_Engine_Config cfg = {};
    cfg.height = 100;
    cfg.width = 500;
    cfg.appName = L"Step1_OS";
    pApp->CreateApp(cfg);
	pApp->ShowCanvas();
    while (1)
    {
        pApp->Tick();
    }
    getchar();
}









//Start Up
OS_APP_ENTRY(AppStart)
