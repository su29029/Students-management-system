//本程序需引用的头文件均在framework.h中
#include "framework.h"
//本程序窗口控件，句柄的ID，函数前向声明，全局变量声明均在resource.h中
#include "resource.h"
//绘制删除信息界面
void SetDeletePage(HWND hWnd) {
	//删除原有控件
	InvalidateRect(hWnd, 0, true);
	DestroyAll();
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
	hTitle = CreateWindow(TEXT("static"), TEXT("删除信息"),
		WS_CHILD | WS_VISIBLE | SS_CENTERIMAGE | SS_CENTER,
		rect.right / 2 - 180 /*x坐标*/, 60 /*y坐标*/, 360 /*宽度*/, 80 /*高度*/,
		hWnd /*父窗口句柄*/, (HMENU)ID_BIG_TITLE /*控件ID*/, hInst /*当前程序实例句柄*/, NULL
	);
	SendMessage(hTitle, WM_SETFONT, (WPARAM)hFontTitle, NULL);

	hDeleteButton = CreateWindow(L"Button", L"确认删除", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON | BS_FLAT,
		rect.right / 2 - 100, 440, 300, 22, hWnd, (HMENU)ID_DELETE_ACK, hInst, NULL);
	SendMessage(hDeleteButton, WM_SETFONT, (WPARAM)hFont, NULL);
	//学生的基本信息：学号，密码，姓名，性别，专业，年级，年龄
	hDeleteID = CreateWindow(TEXT("static"), TEXT("请输入学号："),
		WS_CHILD | WS_VISIBLE | SS_CENTERIMAGE | SS_CENTER,
		rect.right / 2 - 270 /*x坐标*/, 220 /*y坐标*/, 140 /*宽度*/, 22 /*高度*/,
		hWnd /*父窗口句柄*/, (HMENU)ID_DELETE_ID /*控件ID*/, hInst /*当前程序实例句柄*/, NULL
	);
	SendMessage(hDeleteID, WM_SETFONT, (WPARAM)hFont, NULL);

	hDeleteName = CreateWindow(TEXT("static"), TEXT("请输入姓名："),
		WS_CHILD | WS_VISIBLE | SS_CENTERIMAGE | SS_CENTER,
		rect.right / 2 - 270 /*x坐标*/, 260 /*y坐标*/, 140 /*宽度*/, 22 /*高度*/,
		hWnd /*父窗口句柄*/, (HMENU)ID_DELETE_NAME /*控件ID*/, hInst /*当前程序实例句柄*/, NULL
	);
	SendMessage(hDeleteName, WM_SETFONT, (WPARAM)hFont, NULL);

	hDeleteIDText = CreateWindow(TEXT("edit"), NULL, WS_CHILD | WS_VISIBLE |
		WS_BORDER | ES_LEFT | ES_MULTILINE | ES_AUTOHSCROLL |
		ES_AUTOVSCROLL, rect.right / 2 - 100, 220, 300, 22, hWnd, (HMENU)ID_DELETE_ID_TEXT, hInst, NULL);
	SendMessage(hDeleteIDText, WM_SETFONT, (WPARAM)hFont, NULL);
	hDeleteNameText = CreateWindow(TEXT("edit"), NULL, WS_CHILD | WS_VISIBLE |
		WS_BORDER | ES_LEFT | ES_MULTILINE | ES_AUTOHSCROLL |
		ES_AUTOVSCROLL, rect.right / 2 - 100, 260, 300, 22, hWnd, (HMENU)ID_DELETE_NAME_TEXT, hInst, NULL);
	SendMessage(hResizeNameText, WM_SETFONT, (WPARAM)hFont, NULL);

	hReturn = CreateWindow(L"Button", L"返回主界面", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON | BS_FLAT,
		rect.right / 2 - 400, 60, 120, 22, hWnd, (HMENU)ID_RETURN, hInst, NULL);
	SendMessage(hReturn, WM_SETFONT, (WPARAM)hFont, NULL);
}