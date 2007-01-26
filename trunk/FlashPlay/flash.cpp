/******************************************************************
***
***
***				FREE WINDOWLESS FLASH CONTROL
***
***					   by Makarov Igor
***
***		for questions and remarks mailto: mak_july@list.ru
***
***
*******************************************************************/
// flash.cpp : Defines the entry point for the application.
//


#include "stdafx.h"
#include "resource.h"
#include "FlashWnd.h"

#define DllImport  __declspec( dllimport )
#define DllExport  __declspec( dllexport )


#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInstance;								// current instance
TCHAR szTitle[MAX_LOADSTRING];								// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];								// The title bar text

BOOL Running = false;
RECT g_rect;
BOOL g_bSkipFrame;
_bstr_t g_url;
HWND g_hWnd = NULL;
CFlashWnd *g_flashWnd = NULL;

// Foward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance();
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
DWORD WINAPI		ThreadingRun( PVOID pParam );



DllExport BOOL StartFlash(
	HINSTANCE hInst, //启动实例
	PCHAR		url,  //Flash地址
	LONG		left, //窗口位置
    LONG		top,
    LONG		right,
    LONG		bottom,
	BOOL		bSkipFrame //选择隔帧显示
	)
{
	if(Running)
		return false;
	Running = true;
	hInstance = hInst;
	g_url = url;
	g_rect.left = left;
	g_rect.top = top;
	g_rect.right = right;
	g_rect.bottom = bottom;

	g_bSkipFrame = bSkipFrame;
	CreateThread(
		0, 0, ThreadingRun, NULL, 0, 0);
	return true;
}

//---------------------------
//EXE Entry 供测试用        |
//---------------------------
//int APIENTRY WinMain(HINSTANCE hInst,
//                     HINSTANCE hPrevInst,
//                     LPSTR     lpCmdLn,
//                     int       nCmdSw)
//{
//	StartFlash(hInst, "C:\\40.swf", 0,0,1000,1000, false);
//	//delay 3 secs for second call.
//	Sleep(3000);
//	//if last flash is still playing. this call should no effect.
//	StartFlash(hInst, "C:\\40.swf", 0,0,400,400, false);
//
//	while(Running)
//	{
//		Sleep(100);
//	}
//	return 0;
//}



//static int res2file(LPCTSTR lpName,LPCTSTR lpType,LPCTSTR filename)
//{//将从资源写到文件；
//	HRSRC myres	= FindResource (NULL,lpName,lpType);
//	HGLOBAL gl	= LoadResource (NULL,myres);
//	LPVOID lp	= LockResource(gl);
//	HANDLE fp	= CreateFile(filename ,GENERIC_WRITE,0,NULL,CREATE_ALWAYS,
//				0,NULL);
//
//	if (!fp)return false;
//
//	DWORD a;
//	if (!WriteFile (fp,lp,SizeofResource (NULL,myres),&a,NULL))
//		return false;
//
//	CloseHandle (fp);
//	FreeResource (gl);
//	return true;
//
//}


//--------------------
//主显示窗口的线程   |
//--------------------
DWORD WINAPI ThreadingRun( PVOID pParam )
{
	MSG msg;
	//HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_FLASH, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	//
	//res2file (MAKEINTRESOURCE(IDR_SWF2),"swf","c:\\40.swf");

	// Perform application initialization:
	if (!InitInstance ()) 
	{
		return FALSE;
	}

	//hAccelTable = LoadAccelerators(hInstance, (LPCTSTR)IDC_FLASH);

	OleInitialize(NULL);

	g_flashWnd = new CFlashWnd;

	g_flashWnd->m_bSkipFrame = g_bSkipFrame;
	g_flashWnd->m_url = g_url;
	g_flashWnd->m_rcBounds = g_rect;
//create windowless control
	g_flashWnd->Create(ShockwaveFlashObjects::CLSID_ShockwaveFlash,
		WS_EX_LAYERED | WS_EX_TOPMOST, WS_CHILD | WS_POPUP | WS_VISIBLE | WS_CLIPSIBLINGS,
		g_hWnd, hInstance);

	long lTotalFrames, lFrameNum;
	g_flashWnd->m_lpControl->get_TotalFrames(&lTotalFrames);
	lTotalFrames--;
//to create a windowed control uncomment this
	//g_flashWnd->Create(ShockwaveFlashObjects::CLSID_ShockwaveFlash,
	//	0, WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS,
	//	g_hWnd, g_hInst);

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0)) 
	{
		//if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) 
		//{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		//}
		g_flashWnd->m_lpControl->get_FrameNum(&lFrameNum);
		if(lFrameNum >= lTotalFrames)
		{
            PostQuitMessage(0);
		}
	}

	delete g_flashWnd;

	OleUninitialize();
	Running = false;

	return 0;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
//  COMMENTS:
//
//    This function and its usage is only necessary if you want this code
//    to be compatible with Win32 systems prior to the 'RegisterClassEx'
//    function that was added to Windows 95. It is important to call this function
//    so that the application will get 'well formed' small icons associated
//    with it.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX); 

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= (WNDPROC)WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, (LPCTSTR)IDI_FLASH);
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= (LPCSTR)IDC_FLASH;
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, (LPCTSTR)IDI_SMALL);

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HANDLE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance()
{
   HWND hWnd;


   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN,
      CW_USEDEFAULT, CW_USEDEFAULT, 800, 1000, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, SW_HIDE/*SW_SHOW*/);
   UpdateWindow(hWnd);

   g_hWnd = hWnd;

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, unsigned, WORD, LONG)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	TCHAR szHello[MAX_LOADSTRING];
	LoadString(hInstance, IDS_HELLO, szHello, MAX_LOADSTRING);

	switch (message) 
	{
		case WM_COMMAND:
			wmId    = LOWORD(wParam); 
			wmEvent = HIWORD(wParam); 
			// Parse the menu selections:
			switch (wmId)
			{
				case IDM_ABOUT:
				   DialogBox(hInstance, (LPCTSTR)IDD_ABOUTBOX, hWnd, (DLGPROC)About);
				   break;
				case IDM_EXIT:
				   DestroyWindow(hWnd);
				   break;
				default:
				   return DefWindowProc(hWnd, message, wParam, lParam);
			}
			break;
		case WM_PAINT:
			hdc = BeginPaint(hWnd, &ps);
			// TODO: Add any drawing code here...
			RECT rt;
			GetClientRect(hWnd, &rt);
			DrawText(hdc, szHello, strlen(szHello), &rt, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			EndPaint(hWnd, &ps);
			break;
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		case WM_MOVE:
			{
				RECT r;
				GetWindowRect(hWnd, &r);
				if (g_flashWnd)
					SetWindowPos(g_flashWnd->GetHWND(), NULL, r.left, r.top, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
			}
			break;
		case WM_SIZE:
			{
				RECT r;
				GetWindowRect(hWnd, &r);
				if (g_flashWnd)
					SetWindowPos(g_flashWnd->GetHWND(), NULL, 0, 0, (r.right-r.left), (r.bottom-r.top), SWP_NOMOVE | SWP_NOZORDER);
			}
			break;

		case WM_KEYDOWN:
			{
				if (VK_ESCAPE == wParam)
					PostQuitMessage (0);	
			
			}
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
   }
   return 0;
}

// Mesage handler for about box.
LRESULT CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		case WM_INITDIALOG:
				return TRUE;

		case WM_COMMAND:
			if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL) 
			{
				EndDialog(hDlg, LOWORD(wParam));
				return TRUE;
			}
			break;
	}
    return FALSE;
}
