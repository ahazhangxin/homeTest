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
			DestroyWindow(hWnd); return 0;
		} 
	case WM_DESTROY: 
		PostQuitMessage(0); 
		return 0; 
	default: 
		return DefWindowProc(hWnd, message, wParam, lParam); 
	} 
}

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow) 
{ 
	//Step1:注册一个窗口类 
	HWND hwnd;
	//窗口的句柄 
	WNDCLASSEX wc; 
	//窗口类结构 
	wc.cbSize = sizeof(WNDCLASSEX); 
	wc.style = CS_VREDRAW | CS_HREDRAW; wc.lpszMenuName = 0; 
	wc.lpszClassName = _T("Win32"); wc.lpfnWndProc = WinProc; 
	//消息回调函数 
	wc.hInstance = hInstance; 
	wc.hIcon = NULL; 
	wc.hCursor = NULL; 
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1); 
	wc.cbWndExtra = 0; 
	wc.cbClsExtra = 0; 
	wc.hIconSm = NULL; 
	RegisterClassEx(&wc);
	//注册窗口 

	//Step2:创建一个窗口 
	hwnd = CreateWindow( 
		_T("Win32"), //窗口的类名，也就是上面我们自定义的窗口类的名字 
		_T("我的第一个Win32程序"), //窗口的标题 
		WS_OVERLAPPEDWINDOW, //窗口style 
		500, //窗口位置x坐标 
		300, //窗口位置y坐标 
		800, //窗口宽度 
		600, //窗口高度 
		NULL, //父窗口句柄 
		NULL, //菜单句柄 
		hInstance, //实例句柄 
		NULL //创建数据 
		); 
	if (!hwnd) 
	{
		return FALSE; 
	}
	ShowWindow(hwnd, SW_SHOW); 
	//显示窗口 
	UpdateWindow(hwnd); 
	//刷新 
	//Step3:消息循环 
	MSG msg; 
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0; 
}