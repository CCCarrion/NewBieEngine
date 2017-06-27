
#include "Engine/Tools/Config/Config.h"
//#include "Engine/xPlatform/Interface/NBE_Interface_OS.h"
#include "Engine/xPlatform/NBE_OS_Windows/public/NBE_OS_Windows.h"

#pragma comment(lib,"NBE_OS_Windows.lib")

void AppStart()
{
    using NBE_NS_OS;

    OS_APP_Windows* pApp = new OS_APP_Windows();
    NBE_Engine_Config cfg = {};
    cfg.height = 500;
    cfg.width = 500;
    cfg.appName = L"Step1_OS";
    pApp->CreateApp(cfg);
    while (1)
    {
        pApp->Tick();
    }
    delete pApp;
    getchar();
}









//Start Up
OS_APP_ENTRY(AppStart)
