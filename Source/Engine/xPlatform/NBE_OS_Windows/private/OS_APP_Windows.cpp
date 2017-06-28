#include "OS_APP_WIndows.h"



NBE_NS_OS_START
#pragma region Windows App Massage Process

    LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam)
    {
        OS_APP_Windows* app_win = reinterpret_cast<OS_APP_Windows*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
        switch (Message)
        {
        case WM_KEYDOWN:

            break;
        case WM_KEYUP:

            break;
        default:

            break;
        }

        return DefWindowProc(hwnd, Message, wParam, lParam);
    }

    LRESULT CALLBACK WndCreateProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam)
    {
        if (WM_CREATE == Message)
        {
            CREATESTRUCT* pCreate = reinterpret_cast<CREATESTRUCT*>(lParam);
            SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pCreate->lpCreateParams));
            SetWindowLongPtr(hwnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(WndProc));
            return S_OK;
        }
        return DefWindowProc(hwnd, Message, wParam, lParam);
    }


#pragma endregion



    OS_APP_Windows::OS_APP_Windows()
    {

    }

    OS_APP_Windows::~OS_APP_Windows()
    {

    }

    type_NBE_ERR OS_APP_Windows::CreateApp(const NBE_Engine_Config& cfg)
    {
        HINSTANCE hInstance = GetModuleHandle(nullptr);

        WNDCLASSEX wc = {};
        wc.cbSize = sizeof(WNDCLASSEX);
        wc.style = CS_VREDRAW | CS_HREDRAW;
        wc.lpfnWndProc = WndCreateProc;
        wc.hInstance = hInstance;
        wc.hCursor = LoadCursor(NULL, IDC_ARROW);
        wc.lpszClassName = cfg.appName.c_str();
        wc.hIcon = LoadIcon(nullptr, IDC_ICON); //TODO:config indicate the path and load;
        RegisterClassEx(&wc);

        RECT windowRect = { 0,0,static_cast<LONG>(cfg.width),static_cast<LONG>(cfg.height) };
        AdjustWindowRect(&windowRect, WS_OVERLAPPEDWINDOW, FALSE);

        m_hwnd = CreateWindow(
            wc.lpszClassName,
            wc.lpszClassName,
            WS_OVERLAPPEDWINDOW,
            CW_USEDEFAULT,
            CW_USEDEFAULT,
            windowRect.right - windowRect.left,
            windowRect.bottom - windowRect.top,
            nullptr,	//parent window
            nullptr,	//menu handle (no)
            hInstance,
            this		//user class handle the msg
        );

        return NBE_OK;
    }

    void OS_APP_Windows::Tick()
    {
        //Dispatch Msg to proc
        MSG msg;
        while (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }


    }

    type_NBE_ERR OS_APP_Windows::ShowCanvas()
    {
        ShowWindow(m_hwnd, SW_SHOWNORMAL);
        return S_OK;
    }

    HWND OS_APP_Windows::GetAppHandle()
    {
        return m_hwnd;
    }


NBE_NS_OS_END