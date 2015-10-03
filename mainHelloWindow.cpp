// Beginning Game Programming, 2nd Edition
// Chapter 1 - HelloWorld

#include<Windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	MessageBox(NULL, "Peter Huynh is the pure essences of everything awesome.", "This statement is absolute and not conceded.", MB_OK | MB_ICONEXCLAMATION);
}