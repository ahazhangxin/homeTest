#include <Windows.h> 
#include <tchar.h> 
//消息回调函数 
LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) 
{
	switch (message) 
	{
	case WM_CLOSE: 
		if (IDOK == MessageBox(hWnd, _T("你确定退出？"), _T("退出"), MB_OKCANCEL)) 
		{ 
			DestroyWindow(hWnd); 
			return 0; 
		} 
	case WM_DESTROY: 
		PostQuitMessage(0); 
		return 0; 
	default: 
		return DefWindowProc(hWnd, message, wParam, lParam);
	} 
}