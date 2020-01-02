//本程序需引用的头文件均在framework.h中
#include "../framework.h"
//本程序窗口控件，句柄的ID，函数前向声明，全局变量声明均在resource.h中
#include "../resource.h"
//绘制查询信息界面
void SetSearchPage(HWND hWnd) {
	//删除原有控件
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

	hTitle = CreateWindow(TEXT("static"), TEXT("查询信息"),
		WS_CHILD | WS_VISIBLE | SS_CENTERIMAGE | SS_CENTER,
		rect.right / 2 - 180 /*x坐标*/, 60 /*y坐标*/, 360 /*宽度*/, 80 /*高度*/,
		hWnd /*父窗口句柄*/, (HMENU)ID_BIG_TITLE /*控件ID*/, hInst /*当前程序实例句柄*/, NULL
	);
	SendMessage(hTitle, WM_SETFONT, (WPARAM)hFontTitle, NULL);

	hSearchUsername = CreateWindow(TEXT("static"), TEXT("请输入查询学号："),
		WS_CHILD | WS_VISIBLE | SS_CENTERIMAGE | SS_CENTER,
		rect.right / 2 - 270 /*x坐标*/, 260 /*y坐标*/, 140 /*宽度*/, 22 /*高度*/,
		hWnd /*父窗口句柄*/, (HMENU)ID_SEARCH_USERNAME /*控件ID*/, hInst /*当前程序实例句柄*/, NULL
	);
	SendMessage(hSearchUsername, WM_SETFONT, (WPARAM)hFont, NULL);

	hSearchText = CreateWindow(TEXT("edit"), NULL, WS_CHILD | WS_VISIBLE |
		WS_BORDER | ES_LEFT | ES_MULTILINE | ES_AUTOHSCROLL |
		ES_AUTOVSCROLL, rect.right / 2 - 100, 260, 300, 22, hWnd, (HMENU)ID_SEARCH_USERNAME_TEXT, hInst, NULL);
	SendMessage(hSearchText, WM_SETFONT, (WPARAM)hFont, NULL);

	hSearchButton = CreateWindow(L"Button", L"查询", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON | BS_FLAT,
		rect.right / 2 + 230, 260, 100, 22, hWnd, (HMENU)ID_SEARCH_ACK, hInst, NULL);
	SendMessage(hSearchButton, WM_SETFONT, (WPARAM)hFont, NULL);

	hFooter = CreateWindow(TEXT("static"), TEXT("学生信息管理系统 @ HQ WYQ SYQ"),
		WS_CHILD | WS_VISIBLE | SS_CENTERIMAGE | SS_CENTER,
		rect.right / 2 - 120 /*x坐标*/, 500 /*y坐标*/, 240 /*宽度*/, 22 /*高度*/,
		hWnd /*父窗口句柄*/, (HMENU)ID_FOOTER /*控件ID*/, hInst /*当前程序实例句柄*/, NULL
	);
	SendMessage(hFooter, WM_SETFONT, (WPARAM)hFontFooter, NULL);

	hReturn = CreateWindow(L"Button", L"返回主界面", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON | BS_FLAT,
		rect.right / 2 - 400, 60, 120, 22, hWnd, (HMENU)ID_RETURN, hInst, NULL);
	SendMessage(hReturn, WM_SETFONT, (WPARAM)hFont, NULL);

}