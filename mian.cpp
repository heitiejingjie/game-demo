//#include <Windows.h>
//#pragma comment(lib, "winmm.lib")
//
//void FirstInDemo(void);		// 音效和消息简单示例
//void GetMessageDemo(void);
//void PeekMessageDemo(void);
//// 窗口回调/过程函数示例
//LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
//
//int CALLBACK main(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
//{
//	//FirstInDemo();
//	// 窗口类的设计
//	WNDCLASSEX wndClass = { 0 };					// 实例化窗口类
//	{
//		wndClass.cbSize = sizeof(WNDCLASSEX);			// 定义窗口的大小
//		wndClass.style = CS_HREDRAW | CS_VREDRAW;		// 设置窗口的样式水平和垂直重绘
//		//wndClass.lpfnWndProc = "";					// 窗口过程函数，回调函数
//		wndClass.cbClsExtra = 0;						// 窗口的附加内存
//		wndClass.cbWndExtra = 0;						// 窗口实例的附加内存
//		wndClass.hInstance = hInstance;					// 窗口的实例句柄
//		wndClass.hIcon = (HICON)::LoadImage(NULL, L"wndIcon.png", IMAGE_ICON, 0, 0, LR_DEFAULTSIZE | LR_LOADFROMFILE);			  // 加载窗口的图标
//		wndClass.hCursor = LoadCursor(NULL, IDC_ARROW); // 加载窗口的光标
//		wndClass.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);
//		// 设置背景颜色
//		wndClass.lpszMenuName = NULL;					// 设置下拉菜单列表
//		wndClass.lpszClassName = L"firstWindow";		// 设置窗口的名字
//		wndClass.hIconSm = NULL;						// 指定系统菜单栏图标
//	}
//	// 窗口的注册
//	RegisterClassEx(&wndClass);
//
//	// 窗口的正式创建
//	HWND hwnd = CreateWindow(
//		wndClass.lpszClassName,							// 窗口的名称
//		L"致我们永不熄灭的游戏开发梦想",						// 窗口标题
//		WS_OVERLAPPEDWINDOW,							// 窗口的样式
//		CW_USEDEFAULT,									// 窗口的水平位置
//		CW_USEDEFAULT,									// 窗口的垂直位置
//		500,											// 窗口的宽
//		200,											// 窗口的高
//		NULL,											// 窗口的父类句柄
//		NULL,											// 窗口的资源句柄
//		hInstance,										// 窗口的实例
//		NULL											// 窗口的附加参数
//	);
//
//	// 窗口的显示和更新
//	{
//		// 窗口的位置
//		MoveWindow(
//			hwnd,										// 窗口的变量
//			200,										// 窗口的位置
//			50,
//			500,									// 窗口的新大小
//			200,
//			true									// 接受消息后是否刷新
//		);
//		// 窗口的显示
//		ShowWindow(hwnd, SW_SHOW);
//
//		// 窗口的更新
//		UpdateWindow(hwnd);
//	}
//
//	// 传递消息
//	//GetMessage();						// 如果消息队列中没有消息，就一直等待
//	//PeekMessage();					// 如果消息队列中没有消息，也返回，执行
//
//	// windows程序的“中枢神经”窗口过程函数
//
//	// 窗口类的销毁
//
//	return 0;
//}
//
//void FirstInDemo(void)
//{
//	PlaySound(L"1.wav", NULL, SND_FILENAME | SND_ASYNC);// 播放音效
//	MessageBox(NULL, L"你好，Visual Studio!", L"消息窗口", 0);
//}
//
//void GetMessageDemo(void)
//{
//	MSG msg = { 0 };							// 初始化消息
//	while(GetMessage(&msg, NULL, 0, 0))
//	{
//		TranslateMessage(&msg);
//		DispatchMessage(&msg);
//	}
//}
//
//void PeekMessageDemo(void)
//{
//	MSG msg = { 0 };
//	while(msg.message != WM_QUIT)
//	{
//		if(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
//		{
//			TranslateMessage(&msg);
//			DispatchMessage(&msg);
//		}
//		else
//		{
//			//Direct3D_Update();		// 画面更新
//			//Direct3D_Render();		// 画面渲染
//		}
//	}
//}
//
//LRESULT WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
//{
//	switch(message)
//	{
//	case WM_PAINT:								// 客户区重绘消息
//		//Direct3D_Render(hwnd);				// 绘制窗口
//		ValidateRect(hwnd, NULL);			// 更新客户区的显示
//		break;
//
//	case WM_KEYDOWN:							// 键盘按下消息
//		if(wParam == VK_ESCAPE)
//		{
//			DestroyWindow(hwnd);				// 销毁窗口,发送一条WM_Destroy消息
//		}
//		break;
//
//	case WM_DESTROY:							// 窗口销毁消息
//		//Direct3D_cleanUp(hwnd);				// 清理com接口对象
//		PostQuitMessage(0);				// 向系统表明线程有终止请求
//		break;
//
//	default:
//		break;
//	}
//
//	return DefWindowProc(hwnd, message, wParam, lParam);
//}