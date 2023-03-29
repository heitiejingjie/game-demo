#include <Windows.h>

#define WIN_WIDTH 800
#define WIN_HEIGHT 600
#define WIN_TITLE L"【致我们永不熄灭的游戏开发梦想】"

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);											// 回调函数

int WINAPI main(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	// 窗口类的创建
	WNDCLASSEX wndClass = { 0 };
	wndClass.cbSize = sizeof(WNDCLASSEX);
	wndClass.hInstance = hInstance;
	wndClass.style = CS_HREDRAW | CS_VREDRAW;
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.lpfnWndProc = WndProc;
	wndClass.hIcon = (HICON)::LoadImage(NULL, L"wndicon.png", IMAGE_ICON, 0, 0, LR_DEFAULTSIZE | LR_LOADFROMFILE);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndClass.lpszClassName = L"firstWindow";
	wndClass.lpszMenuName = NULL;

	// 窗口类的注册
	if(!RegisterClassEx(&wndClass)) return -1;

	// 正式创建窗口
	HWND hWnd = CreateWindow(wndClass.lpszClassName, WIN_TITLE, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, WIN_WIDTH, WIN_HEIGHT, NULL, NULL, hInstance, NULL);

	// 窗口的移动、显示和更新
	MoveWindow(hWnd, 250, 80, WIN_WIDTH, WIN_HEIGHT, true);

	ShowWindow(hWnd, nShowCmd);

	UpdateWindow(hWnd);

	// 消息循环
	MSG msg = { 0 };
	while(msg.message != WM_QUIT)
	{
		if(PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	// 窗口的销毁
	UnregisterClass(wndClass.lpszClassName, hInstance);

	return 0;
}

LRESULT WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch(message)
	{
	case WM_PAINT:				// 重绘消息
		ValidateRect(hwnd, NULL);
		break;

	case WM_KEYDOWN:
		if(wParam == VK_ESCAPE)
		{
			DestroyWindow(hwnd);
		}
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}

	return 0;
}