//本程序需引用的头文件均在framework.h中
#include "framework.h"
//本程序窗口控件，句柄的ID，函数前向声明，全局变量声明均在resource.h中
#include "resource.h"
//绘制登录信息界面
void SetLoginPage(HWND hWnd) {
	isLogin = STATUS_LOGIN_NO;
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


	//添加新的控件
	hTitle = CreateWindow(TEXT("static"), TEXT("欢迎使用学生信息管理系统"),
		WS_CHILD | WS_VISIBLE | SS_CENTERIMAGE | SS_CENTER,
		rect.right / 2 - 180 /*x坐标*/, 60 /*y坐标*/, 360 /*宽度*/, 80 /*高度*/,
		hWnd /*父窗口句柄*/, (HMENU)ID_BIG_TITLE /*控件ID*/, hInst /*当前程序实例句柄*/, NULL
	);
	SendMessage(hTitle, WM_SETFONT, (WPARAM)hFontTitle, NULL);

	hUsername = CreateWindow(TEXT("static"), TEXT("学号"),
		WS_CHILD | WS_VISIBLE | SS_CENTERIMAGE | SS_CENTER,
		rect.right / 2 - 230 /*x坐标*/, 220 /*y坐标*/, 60 /*宽度*/, 22 /*高度*/,
		hWnd /*父窗口句柄*/, (HMENU)ID_LOGIN_USERNAME /*控件ID*/, hInst /*当前程序实例句柄*/, NULL
	);
	SendMessage(hUsername, WM_SETFONT, (WPARAM)hFont, NULL);

	hPassword = CreateWindow(TEXT("static"), TEXT("密码"),
		WS_CHILD | WS_VISIBLE | SS_CENTERIMAGE | SS_CENTER,
		rect.right / 2 - 230 /*x坐标*/, 260 /*y坐标*/, 60 /*宽度*/, 22 /*高度*/,
		hWnd /*父窗口句柄*/, (HMENU)ID_LOGIN_PASSWORD /*控件ID*/, hInst /*当前程序实例句柄*/, NULL
	);
	SendMessage(hPassword, WM_SETFONT, (WPARAM)hFont, NULL);

	hFooter = CreateWindow(TEXT("static"), TEXT("学生信息管理系统 @ HQ WYQ SYQ"),
		WS_CHILD | WS_VISIBLE | SS_CENTERIMAGE | SS_CENTER,
		rect.right / 2 - 120 /*x坐标*/, 500 /*y坐标*/, 240 /*宽度*/, 22 /*高度*/,
		hWnd /*父窗口句柄*/, (HMENU)ID_FOOTER /*控件ID*/, hInst /*当前程序实例句柄*/, NULL
	);
	SendMessage(hFooter, WM_SETFONT, (WPARAM)hFontFooter, NULL);

	hLogin = CreateWindow(L"Button", L"登录", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON | BS_FLAT,
		rect.right / 2 - 150, 300, 100, 30, hWnd, (HMENU)IDBTN_LOG, hInst, NULL);
	SendMessage(hLogin, WM_SETFONT, (WPARAM)hFontFooter, NULL);

	hRegister = CreateWindow(L"Button", L"注册", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON | BS_FLAT,
		rect.right / 2 + 50, 300, 100, 30, hWnd, (HMENU)IDBTN_REG, hInst, NULL);
	SendMessage(hRegister, WM_SETFONT, (WPARAM)hFontFooter, NULL);

	hLoginText = CreateWindow(TEXT("edit"), NULL, WS_CHILD | WS_VISIBLE |
		WS_BORDER | ES_LEFT | ES_MULTILINE | ES_AUTOHSCROLL |
		ES_AUTOVSCROLL, rect.right / 2 - 150, 220, 300, 22, hWnd, (HMENU)ID_LOGIN_USERNAME_TEXT, hInst, NULL);

	hPasswordText = CreateWindow(TEXT("edit"), NULL, WS_CHILD | WS_VISIBLE |
		WS_BORDER | ES_PASSWORD, rect.right / 2 - 150, 260, 300, 22, hWnd, (HMENU)ID_LOGIN_PASSWORD_TEXT, hInst, NULL);

	UpdateWindow(hWnd);

}