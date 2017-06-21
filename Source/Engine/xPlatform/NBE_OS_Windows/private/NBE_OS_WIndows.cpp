#include "../public/NBE_OS_WIndows.h"

namespace NBE::OS
{

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
		
	}

	LRESULT CALLBACK OS_APP_Windows::WndCreateProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam)
	{

	}

	LRESULT CALLBACK OS_APP_Windows::WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam)
	{

	}

}