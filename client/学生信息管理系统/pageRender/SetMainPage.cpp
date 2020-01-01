//本程序需引用的头文件均在framework.h中
#include "framework.h"
//本程序窗口控件，句柄的ID，函数前向声明，全局变量声明均在resource.h中
#include "resource.h"
//绘制登录后主页面
void SetMainPage(HWND hWnd) {

	//删除页面原有控件
	InvalidateRect(hWnd, 0, true);
	DestroyAll();

	//设置字体
	hBrush = CreateSolidBrush(RGB(0x41, 0x96, 0x4F));
	hFontTitle = CreateFont(-28/*高*/, -14/*宽*/, 0, 0, 700 /*粗体*/,
		FALSE/*斜体*/, FALSE/*下划线*/, FALSE/*删除线*/, DEFAULT_CHARSET,
		OUT_CHARACTER_PRECIS, CLIP_CHARACTER_PRECIS, DEFAULT_QUALITY,
		FF_DONTCARE, TEXT("微软雅黑")
	);
	hFont = CreateFont(-16/*高*/, -8/*宽*/, 0, 0, 500 /*粗体*/,
		FALSE/*斜体*/, FALSE/*下划线*/, FALSE/*删除线*/, DEFAULT_CHARSET,
		OUT_CHARACTER_PRECIS, CLIP_CHARACTER_PRECIS, DEFAULT_QUALITY,
		FF_DONTCARE, TEXT("微软雅黑")
	);
	hFontFooter = CreateFont(-14/*高*/, -7/*宽*/, 0, 0, 200 /*粗体*/,
		FALSE/*斜体*/, FALSE/*下划线*/, FALSE/*删除线*/, DEFAULT_CHARSET,
		OUT_CHARACTER_PRECIS, CLIP_CHARACTER_PRECIS, DEFAULT_QUALITY,
		FF_DONTCARE, TEXT("微软雅黑")
	);

	//创建新的控件
	hTitle = CreateWindow(TEXT("static"), TEXT("欢迎登录，请选择："),
		WS_CHILD | WS_VISIBLE | SS_CENTERIMAGE | SS_CENTER,
		rect.right / 2 - 180 /*x坐标*/, 60 /*y坐标*/, 360 /*宽度*/, 80 /*高度*/,
		hWnd /*父窗口句柄*/, (HMENU)ID_BIG_TITLE /*控件ID*/, hInst /*当前程序实例句柄*/, NULL
	);
	SendMessage(hTitle, WM_SETFONT, (WPARAM)hFontTitle, NULL);
	hSearch = CreateWindow(TEXT("Button"), TEXT("查询信息"),
		WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON | BS_FLAT,
		rect.right / 2 - 120 /*x坐标*/, 180 /*y坐标*/, 240 /*宽度*/, 22 /*高度*/,
		hWnd /*父窗口句柄*/, (HMENU)ID_SEARCH /*控件ID*/, hInst /*当前程序实例句柄*/, NULL
	);
	SendMessage(hSearch, WM_SETFONT, (WPARAM)hFont, NULL);
	hResize = CreateWindow(TEXT("Button"), TEXT("修改信息"),
		WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON | BS_FLAT,
		rect.right / 2 - 120 /*x坐标*/, 240 /*y坐标*/, 240 /*宽度*/, 22 /*高度*/,
		hWnd /*父窗口句柄*/, (HMENU)ID_RESIZE /*控件ID*/, hInst /*当前程序实例句柄*/, NULL
	);
	SendMessage(hResize, WM_SETFONT, (WPARAM)hFont, NULL);
	hAdd = CreateWindow(TEXT("Button"), TEXT("添加信息"),
		WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON | BS_FLAT,
		rect.right / 2 - 120 /*x坐标*/, 300 /*y坐标*/, 240 /*宽度*/, 22 /*高度*/,
		hWnd /*父窗口句柄*/, (HMENU)ID_ADD /*控件ID*/, hInst /*当前程序实例句柄*/, NULL
	);
	SendMessage(hAdd, WM_SETFONT, (WPARAM)hFont, NULL);
	hDelete = CreateWindow(TEXT("Button"), TEXT("删除信息"),
		WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON | BS_FLAT,
		rect.right / 2 - 120 /*x坐标*/, 360 /*y坐标*/, 240 /*宽度*/, 22 /*高度*/,
		hWnd /*父窗口句柄*/, (HMENU)ID_DELETE /*控件ID*/, hInst /*当前程序实例句柄*/, NULL
	);
	SendMessage(hDelete, WM_SETFONT, (WPARAM)hFont, NULL);
	hFooter = CreateWindow(TEXT("static"), TEXT("学生信息管理系统 @ HQ WYQ SYQ"),
		WS_CHILD | WS_VISIBLE | SS_CENTERIMAGE | SS_CENTER,
		rect.right / 2 - 120 /*x坐标*/, 500 /*y坐标*/, 240 /*宽度*/, 22 /*高度*/,
		hWnd /*父窗口句柄*/, (HMENU)ID_FOOTER /*控件ID*/, hInst /*当前程序实例句柄*/, NULL
	);
	SendMessage(hFooter, WM_SETFONT, (WPARAM)hFontFooter, NULL);

	UpdateWindow(hWnd);

}