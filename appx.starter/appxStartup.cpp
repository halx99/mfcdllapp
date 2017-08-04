#include <Windows.h>
typedef int (__stdcall* PAfxWinMain)(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	_In_ LPTSTR lpCmdLine, int nCmdShow);

extern "C" int WINAPI
wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	_In_ LPTSTR lpCmdLine, int nCmdShow)
#pragma warning(suppress: 4985)
{
	auto hCoreDLL = LoadLibrary(L"appx.core.dll");
	PAfxWinMain AfxWinMain = (PAfxWinMain)GetProcAddress(hCoreDLL, "StartApplication");
	// call shared/exported WinMain
	return AfxWinMain(hInstance, hPrevInstance, lpCmdLine, nCmdShow);
}
