// Beginning Game Programming, 3rd Edition
// Chapter 2 - WorldTest

#include<windows.h>
#include<iostream>
using namespace std;

const string ProgramTitle="World Test Program";

// Window Event Callback Function
LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	string text = "World Test!";

	switch(message)
	{
		case WM_PAINT:
		{
			// Getting Window Deminsions
			RECT rt;
			GetClientRect(hWnd, &rt);

			// Drawing Device Context
			PAINTSTRUCT ps;
			HDC hdc = BeginPaint(hWnd, &ps);

			// Text Drawing
			DrawText(hdc, text.c_str(), text.length(), &rt, DT_CENTER);

			// 1000 Random Pixels for Drawing
			for(int n=0; n<3000; n++)
			{
				int x = rand() % (rt.right - rt.left);
				int y = rand() % (rt.bottom - rt.top);
				COLORREF c = RGB(rand()%256, rand()%256, rand()%256);
				SetPixel(hdc, x, y, c);
			}

			// Stopping
			EndPaint(hWnd, &ps);
		};
		break;

		case WM_DESTROY:
			PostQuitMessage(0);
			break;
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}

// Set up Window Properties Helper Function
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	// Setting New Window's Properties
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = (WNDPROC)WinProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = NULL;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = ProgramTitle.c_str();
	wc.hIconSm = NULL;
	return RegisterClassEx(&wc);
}

// Create and Refresh Window Helper Function
bool InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	//New window Creation
	HWND hWnd = CreateWindow
		(
			ProgramTitle.c_str(),			// Window Class
			ProgramTitle.c_str(),			// Title Bar
			WS_OVERLAPPEDWINDOW,			// Window Style
			CW_USEDEFAULT, CW_USEDEFAULT,	// Window Position
			640, 480,						// Window Dimensions
			NULL,							// Unused Parent Window
			NULL,							// Unused Menu
			hInstance,						// Application Instance
			NULL							// Unused Window Parameters
		);

	//If there's error with creating the window
	if(hWnd == 0) return 0;

	//Displaying Window
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return 1;
}

// Windows Program Entry
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// Creating Window
	MyRegisterClass(hInstance);
	if (!InitInstance (hInstance, nCmdShow)) return 0;

	// Main Message Loop
	MSG msg;
	while(GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}