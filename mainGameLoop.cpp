// Beginning Game Programming, Third Edition
// Chapter 2
// GameLoop Project

#include<windows.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<time.h>
using namespace std;

const string APPTITLE = "Game Loop";
HWND window;
HDC device;
bool gameover = false;

// Loads, Draws, and Wipes a Bitmap
void DrawBitmap(char *filename, int x, int y)
{
	// Loading the Bitmap
	HBITMAP image = (HBITMAP)LoadImage(0,"c.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);

	// Reading the Bitmap Properties
	BITMAP bm;
	GetObject(image, sizeof(BITMAP), &bm);

	// Creating Device Context for the Bitmap
	HDC hdcImage = CreateCompatibleDC(device);
	SelectObject(hdcImage, image);

	// Drawing the Bitmap
	BitBlt
	(
		device,						// Destination Device Context
		x, y,						// Location on Destination
		bm.bmWidth, bm.bmHeight,	// Size of Bitmap
		hdcImage,					// Source Bitmap Device Context
		0,0,						// Start on Source Bitmap
		SRCCOPY						// blit Method
	);

	// Deleting the Device Context and Bitmap
	DeleteDC(hdcImage);
	DeleteObject((HBITMAP)image);
}

// Startup and Loading
bool Game_Init()
{
	// Startup Random # Generator
	srand(time(NULL));
	
	return 1;
}

// Update Fuction Inside Game Loop
void Game_Run()
{
	if (gameover == true)return;

	// Getting the Drawing Surface
//	RECT rect;
//	GetClientRect(window, &rect);

	// Drawing Bitmap at Random Location
//	int x = rand() % (rect.right - rect.left);
//	int y = rand() % (rect.bottom - rect.top);
	
	int i = 0;
	int j = 0;

	if (i <= 640) 
		i++;
	else if (i >= 0)
		i--;

	if(j <= 480) 
		j++;
	else if (i >= 0)
		j--;

	int x = i;
	int y = j;
	
	DrawBitmap("c.bmp",x,y);
}

// Shutting Down
void Game_End()
{
	// Freeing the Device
	ReleaseDC(window, device);
}

// Window Callback Function
LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch(message)
	{
	case WM_DESTROY:
		gameover = true;
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hWnd,message,wParam,lParam);
}

// Program Window Properties
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	// Window Class Structure
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);

	//Structure Information
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = (WNDPROC)WinProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = NULL;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);		// Originally NULL
	wc.lpszMenuName = NULL;
	wc.lpszClassName = APPTITLE.c_str();
	wc.hIconSm = NULL;

	// Window with Class Info
	return RegisterClassEx(&wc);
}

// Helper Function to Create/Refresh Window
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{

	// Creating a New Window
	window = CreateWindow
	(
		APPTITLE.c_str(),		// Window Class
		APPTITLE.c_str(),		// Title Bar
		WS_OVERLAPPEDWINDOW,	// Window Style
		CW_USEDEFAULT,			// X Position
		CW_USEDEFAULT,			// Y Position
		640,					// Width
		480,					// Height
		NULL,					// Parent Window
		NULL,					// Menu
		hInstance,				// Application Instance
		NULL					// Window Parameters
	);

	// Error Creating Window
	if(window == 0) return 0;

	// Displaying the window
	ShowWindow(window, nCmdShow);
	UpdateWindow(window);

	// Device Context for Drawing
	device = GetDC(window);

	return 1;
}

// Entry Point Function
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	MSG msg;

	// Creating Window
	MyRegisterClass(hInstance);
	if(!InitInstance(hInstance, nCmdShow)) return 0;

	// Initializing Game
	if(!Game_Init()) return 0;

	// Main Message Loop
	while(!gameover)
	{
		// Processing Windows Events
		if(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		// Processing Game Loop
		Game_Run();
	}

	// Free Game Resources
	Game_End();

	return msg.wParam;
}