//本程序需引用的头文件均在framework.h中
#include "../framework.h"
//本程序窗口控件，句柄的ID，函数前向声明，全局变量声明均在resource.h中
#include "../resource.h"
//绘制修改信息界面
void SetResizeSettingPage(HWND hWnd) {
	InvalidateRect(hWnd, 0, true);
	DestroyWindow(hReturn);
	DestroyWindow(hResizeUsername);
	DestroyWindow(hResizeText);
	DestroyWindow(hResizeButton);
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
	hTitle = CreateWindow(TEXT("static"), TEXT("修改信息"),
		WS_CHILD | WS_VISIBLE | SS_CENTERIMAGE | SS_CENTER,
		rect.right / 2 - 180 /*x坐标*/, 60 /*y坐标*/, 360 /*宽度*/, 80 /*高度*/,
		hWnd /*父窗口句柄*/, (HMENU)ID_BIG_TITLE /*控件ID*/, hInst /*当前程序实例句柄*/, NULL
	);
	SendMessage(hTitle, WM_SETFONT, (WPARAM)hFontTitle, NULL);

	//学生的基本信息：姓名，性别，专业，年龄
	hResizeSettingName = CreateWindow(TEXT("static"), TEXT("请输入姓名："),
		WS_CHILD | WS_VISIBLE | SS_CENTERIMAGE | SS_CENTER,
		rect.right / 2 - 270 /*x坐标*/, 210 /*y坐标*/, 140 /*宽度*/, 22 /*高度*/,
		hWnd /*父窗口句柄*/, (HMENU)ID_RESIZE_SETTING_NAME /*控件ID*/, hInst /*当前程序实例句柄*/, NULL
	);
	SendMessage(hResizeSettingName, WM_SETFONT, (WPARAM)hFont, NULL);
	hResizeSettingSex = CreateWindow(TEXT("static"), TEXT("请输入性别："),
		WS_CHILD | WS_VISIBLE | SS_CENTERIMAGE | SS_CENTER,
		rect.right / 2 - 270 /*x坐标*/, 245 /*y坐标*/, 140 /*宽度*/, 22 /*高度*/,
		hWnd /*父窗口句柄*/, (HMENU)ID_RESIZE_SETTING_SEX /*控件ID*/, hInst /*当前程序实例句柄*/, NULL
	);
	SendMessage(hResizeSettingSex, WM_SETFONT, (WPARAM)hFont, NULL);
	hResizeSettingMajor = CreateWindow(TEXT("static"), TEXT("请输入专业："),
		WS_CHILD | WS_VISIBLE | SS_CENTERIMAGE | SS_CENTER,
		rect.right / 2 - 270 /*x坐标*/, 280 /*y坐标*/, 140 /*宽度*/, 22 /*高度*/,
		hWnd /*父窗口句柄*/, (HMENU)ID_RESIZE_SETTING_MAJOR /*控件ID*/, hInst /*当前程序实例句柄*/, NULL
	);
	SendMessage(hResizeSettingMajor, WM_SETFONT, (WPARAM)hFont, NULL);
	hResizeSettingGrade = CreateWindow(TEXT("static"), TEXT("请输入年级："),
		WS_CHILD | WS_VISIBLE | SS_CENTERIMAGE | SS_CENTER,
		rect.right / 2 - 270 /*x坐标*/, 315 /*y坐标*/, 140 /*宽度*/, 22 /*高度*/,
		hWnd /*父窗口句柄*/, (HMENU)ID_RESIZE_SETTING_GRADE /*控件ID*/, hInst /*当前程序实例句柄*/, NULL
	);
	SendMessage(hResizeSettingGrade, WM_SETFONT, (WPARAM)hFont, NULL);
	hResizeSettingAge = CreateWindow(TEXT("static"), TEXT("请输入年龄："),
		WS_CHILD | WS_VISIBLE | SS_CENTERIMAGE | SS_CENTER,
		rect.right / 2 - 270 /*x坐标*/, 350 /*y坐标*/, 140 /*宽度*/, 22 /*高度*/,
		hWnd /*父窗口句柄*/, (HMENU)ID_RESIZE_SETTING_AGE /*控件ID*/, hInst /*当前程序实例句柄*/, NULL
	);
	SendMessage(hResizeSettingAge, WM_SETFONT, (WPARAM)hFont, NULL);
	hResizeSettingMidTermScore = CreateWindow(TEXT("static"), TEXT("请输入期中成绩："),
		WS_CHILD | WS_VISIBLE | SS_CENTERIMAGE | SS_CENTER,
		rect.right / 2 - 270 /*x坐标*/, 385 /*y坐标*/, 140 /*宽度*/, 22 /*高度*/,
		hWnd /*父窗口句柄*/, (HMENU)ID_RESIZE_SETTING_MID /*控件ID*/, hInst /*当前程序实例句柄*/, NULL
	);
	SendMessage(hResizeSettingMidTermScore, WM_SETFONT, (WPARAM)hFont, NULL);
	hResizeSettingFinalTermScore = CreateWindow(TEXT("static"), TEXT("请输入期末成绩："),
		WS_CHILD | WS_VISIBLE | SS_CENTERIMAGE | SS_CENTER,
		rect.right / 2 - 270 /*x坐标*/, 420 /*y坐标*/, 140 /*宽度*/, 22 /*高度*/,
		hWnd /*父窗口句柄*/, (HMENU)ID_RESIZE_SETTING_FINAL /*控件ID*/, hInst /*当前程序实例句柄*/, NULL
	);
	SendMessage(hResizeSettingFinalTermScore, WM_SETFONT, (WPARAM)hFont, NULL);

	hResizeSettingButton = CreateWindow(L"Button", L"确认修改", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON | BS_FLAT,
		rect.right / 2 - 100, 460, 300, 22, hWnd, (HMENU)ID_RESIZE_SETTING_ACK, hInst, NULL);
	SendMessage(hResizeSettingButton, WM_SETFONT, (WPARAM)hFont, NULL);

	hResizeNameText = CreateWindow(TEXT("edit"), NULL, WS_CHILD | WS_VISIBLE |
		WS_BORDER | ES_LEFT | ES_MULTILINE | ES_AUTOHSCROLL |
		ES_AUTOVSCROLL, rect.right / 2 - 100, 210, 300, 22, hWnd, (HMENU)ID_RESIZE_SETTING_NAME_TEXT, hInst, NULL);
	SendMessage(hResizeNameText, WM_SETFONT, (WPARAM)hFont, NULL);
	hResizeSexText = CreateWindow(TEXT("edit"), NULL, WS_CHILD | WS_VISIBLE |
		WS_BORDER | ES_LEFT | ES_MULTILINE | ES_AUTOHSCROLL |
		ES_AUTOVSCROLL, rect.right / 2 - 100, 245, 300, 22, hWnd, (HMENU)ID_RESIZE_SETTING_SEX_TEXT, hInst, NULL);
	SendMessage(hResizeSexText, WM_SETFONT, (WPARAM)hFont, NULL);
	hResizeMajorText = CreateWindow(TEXT("edit"), NULL, WS_CHILD | WS_VISIBLE |
		WS_BORDER | ES_LEFT | ES_MULTILINE | ES_AUTOHSCROLL |
		ES_AUTOVSCROLL, rect.right / 2 - 100, 280, 300, 22, hWnd, (HMENU)ID_RESIZE_SETTING_MAJOR_TEXT, hInst, NULL);
	SendMessage(hResizeMajorText, WM_SETFONT, (WPARAM)hFont, NULL);
	hResizeGradeText = CreateWindow(TEXT("edit"), NULL, WS_CHILD | WS_VISIBLE |
		WS_BORDER | ES_LEFT | ES_MULTILINE | ES_AUTOHSCROLL |
		ES_AUTOVSCROLL, rect.right / 2 - 100, 315, 300, 22, hWnd, (HMENU)ID_RESIZE_SETTING_GRADE_TEXT, hInst, NULL);
	SendMessage(hResizeGradeText, WM_SETFONT, (WPARAM)hFont, NULL);
	hResizeAgeText = CreateWindow(TEXT("edit"), NULL, WS_CHILD | WS_VISIBLE |
		WS_BORDER | ES_LEFT | ES_MULTILINE | ES_AUTOHSCROLL |
		ES_AUTOVSCROLL, rect.right / 2 - 100, 350, 300, 22, hWnd, (HMENU)ID_RESIZE_SETTING_AGE_TEXT, hInst, NULL);
	SendMessage(hResizeAgeText, WM_SETFONT, (WPARAM)hFont, NULL);
	hResizeMidText = CreateWindow(TEXT("edit"), NULL, WS_CHILD | WS_VISIBLE |
		WS_BORDER | ES_LEFT | ES_MULTILINE | ES_AUTOHSCROLL |
		ES_AUTOVSCROLL, rect.right / 2 - 100, 385, 300, 22, hWnd, (HMENU)ID_RESIZE_SETTING_MID_TEXT, hInst, NULL);
	SendMessage(hResizeMidText, WM_SETFONT, (WPARAM)hFont, NULL);
	hResizeFinalText = CreateWindow(TEXT("edit"), NULL, WS_CHILD | WS_VISIBLE |
		WS_BORDER | ES_LEFT | ES_MULTILINE | ES_AUTOHSCROLL |
		ES_AUTOVSCROLL, rect.right / 2 - 100, 420, 300, 22, hWnd, (HMENU)ID_RESIZE_SETTING_FINAL_TEXT, hInst, NULL);
	SendMessage(hResizeFinalText, WM_SETFONT, (WPARAM)hFont, NULL);
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