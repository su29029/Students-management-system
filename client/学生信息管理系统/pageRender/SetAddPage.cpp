//本程序需引用的头文件均在framework.h中
#include "../framework.h"
//本程序窗口控件，句柄的ID，函数前向声明，全局变量声明均在resource.h中
#include "../resource.h"
//绘制添加信息（注册）界面
void SetAddPage(HWND hWnd) {
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
	hTitle = CreateWindow(TEXT("static"), TEXT("添加信息/注册信息"),
		WS_CHILD | WS_VISIBLE | SS_CENTERIMAGE | SS_CENTER,
		rect.right / 2 - 180 /*x坐标*/, 60 /*y坐标*/, 360 /*宽度*/, 80 /*高度*/,
		hWnd /*父窗口句柄*/, (HMENU)ID_BIG_TITLE /*控件ID*/, hInst /*当前程序实例句柄*/, NULL
	);
	SendMessage(hTitle, WM_SETFONT, (WPARAM)hFontTitle, NULL);


	//学生的基本信息：学号，密码，姓名，性别，专业，年级，年龄
	hAddID = CreateWindow(TEXT("static"), TEXT("请输入学号："),
		WS_CHILD | WS_VISIBLE | SS_CENTERIMAGE | SS_CENTER,
		rect.right / 2 - 270 /*x坐标*/, 210 /*y坐标*/, 140 /*宽度*/, 22 /*高度*/,
		hWnd /*父窗口句柄*/, (HMENU)ID_ADD_ID /*控件ID*/, hInst /*当前程序实例句柄*/, NULL
	);
	SendMessage(hAddID, WM_SETFONT, (WPARAM)hFont, NULL);
	hAddPassword = CreateWindow(TEXT("static"), TEXT("请输入密码："),
		WS_CHILD | WS_VISIBLE | SS_CENTERIMAGE | SS_CENTER,
		rect.right / 2 - 270 /*x坐标*/, 245 /*y坐标*/, 140 /*宽度*/, 22 /*高度*/,
		hWnd /*父窗口句柄*/, (HMENU)ID_ADD_PASSWORD /*控件ID*/, hInst /*当前程序实例句柄*/, NULL
	);
	SendMessage(hAddPassword, WM_SETFONT, (WPARAM)hFont, NULL);
	hAddName = CreateWindow(TEXT("static"), TEXT("请输入姓名："),
		WS_CHILD | WS_VISIBLE | SS_CENTERIMAGE | SS_CENTER,
		rect.right / 2 - 270 /*x坐标*/, 280 /*y坐标*/, 140 /*宽度*/, 22 /*高度*/,
		hWnd /*父窗口句柄*/, (HMENU)ID_ADD_NAME /*控件ID*/, hInst /*当前程序实例句柄*/, NULL
	);
	SendMessage(hAddName, WM_SETFONT, (WPARAM)hFont, NULL);
	hAddSex = CreateWindow(TEXT("static"), TEXT("请输入性别："),
		WS_CHILD | WS_VISIBLE | SS_CENTERIMAGE | SS_CENTER,
		rect.right / 2 - 270 /*x坐标*/, 315 /*y坐标*/, 140 /*宽度*/, 22 /*高度*/,
		hWnd /*父窗口句柄*/, (HMENU)ID_ADD_SEX /*控件ID*/, hInst /*当前程序实例句柄*/, NULL
	);
	SendMessage(hAddSex, WM_SETFONT, (WPARAM)hFont, NULL);
	hAddMajor = CreateWindow(TEXT("static"), TEXT("请输入专业："),
		WS_CHILD | WS_VISIBLE | SS_CENTERIMAGE | SS_CENTER,
		rect.right / 2 - 270 /*x坐标*/, 350 /*y坐标*/, 140 /*宽度*/, 22 /*高度*/,
		hWnd /*父窗口句柄*/, (HMENU)ID_ADD_MAJOR /*控件ID*/, hInst /*当前程序实例句柄*/, NULL
	);
	SendMessage(hAddMajor, WM_SETFONT, (WPARAM)hFont, NULL);
	hAddGrade = CreateWindow(TEXT("static"), TEXT("请输入年级："),
		WS_CHILD | WS_VISIBLE | SS_CENTERIMAGE | SS_CENTER,
		rect.right / 2 - 270 /*x坐标*/, 385 /*y坐标*/, 140 /*宽度*/, 22 /*高度*/,
		hWnd /*父窗口句柄*/, (HMENU)ID_ADD_GRADE /*控件ID*/, hInst /*当前程序实例句柄*/, NULL
	);
	SendMessage(hAddGrade, WM_SETFONT, (WPARAM)hFont, NULL);
	hAddAge = CreateWindow(TEXT("static"), TEXT("请输入年龄："),
		WS_CHILD | WS_VISIBLE | SS_CENTERIMAGE | SS_CENTER,
		rect.right / 2 - 270 /*x坐标*/, 420 /*y坐标*/, 140 /*宽度*/, 22 /*高度*/,
		hWnd /*父窗口句柄*/, (HMENU)ID_ADD_AGE /*控件ID*/, hInst /*当前程序实例句柄*/, NULL
	);
	SendMessage(hAddAge, WM_SETFONT, (WPARAM)hFont, NULL);

	hAddButton = CreateWindow(L"Button", L"确认添加", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON | BS_FLAT,
		rect.right / 2 - 100, 460, 300, 22, hWnd, (HMENU)ID_ADD_ACK, hInst, NULL);
	SendMessage(hAddButton, WM_SETFONT, (WPARAM)hFont, NULL);

	hAddIDText = CreateWindow(TEXT("edit"), NULL, WS_CHILD | WS_VISIBLE |
		WS_BORDER | ES_LEFT | ES_MULTILINE | ES_AUTOHSCROLL |
		ES_AUTOVSCROLL, rect.right / 2 - 100, 210, 300, 22, hWnd, (HMENU)ID_ADD_ID_TEXT, hInst, NULL);
	SendMessage(hAddIDText, WM_SETFONT, (WPARAM)hFont, NULL);
	hAddPasswordText = CreateWindow(TEXT("edit"), NULL, WS_CHILD | WS_VISIBLE |
		WS_BORDER | ES_LEFT | ES_MULTILINE | ES_AUTOHSCROLL |
		ES_AUTOVSCROLL, rect.right / 2 - 100, 245, 300, 22, hWnd, (HMENU)ID_ADD_PASSWORD_TEXT, hInst, NULL);
	SendMessage(hAddPasswordText, WM_SETFONT, (WPARAM)hFont, NULL);
	hAddNameText = CreateWindow(TEXT("edit"), NULL, WS_CHILD | WS_VISIBLE |
		WS_BORDER | ES_LEFT | ES_MULTILINE | ES_AUTOHSCROLL |
		ES_AUTOVSCROLL, rect.right / 2 - 100, 280, 300, 22, hWnd, (HMENU)ID_ADD_NAME_TEXT, hInst, NULL);
	SendMessage(hAddNameText, WM_SETFONT, (WPARAM)hFont, NULL);
	hAddSexText = CreateWindow(TEXT("edit"), NULL, WS_CHILD | WS_VISIBLE |
		WS_BORDER | ES_LEFT | ES_MULTILINE | ES_AUTOHSCROLL |
		ES_AUTOVSCROLL, rect.right / 2 - 100, 315, 300, 22, hWnd, (HMENU)ID_ADD_SEX_TEXT, hInst, NULL);
	SendMessage(hAddSexText, WM_SETFONT, (WPARAM)hFont, NULL);
	hAddMajorText = CreateWindow(TEXT("edit"), NULL, WS_CHILD | WS_VISIBLE |
		WS_BORDER | ES_LEFT | ES_MULTILINE | ES_AUTOHSCROLL |
		ES_AUTOVSCROLL, rect.right / 2 - 100, 350, 300, 22, hWnd, (HMENU)ID_ADD_MAJOR_TEXT, hInst, NULL);
	SendMessage(hAddMajorText, WM_SETFONT, (WPARAM)hFont, NULL);
	hAddGradeText = CreateWindow(TEXT("edit"), NULL, WS_CHILD | WS_VISIBLE |
		WS_BORDER | ES_LEFT | ES_MULTILINE | ES_AUTOHSCROLL |
		ES_AUTOVSCROLL, rect.right / 2 - 100, 385, 300, 22, hWnd, (HMENU)ID_ADD_GRADE_TEXT, hInst, NULL);
	SendMessage(hAddGradeText, WM_SETFONT, (WPARAM)hFont, NULL);
	hAddAgeText = CreateWindow(TEXT("edit"), NULL, WS_CHILD | WS_VISIBLE |
		WS_BORDER | ES_LEFT | ES_MULTILINE | ES_AUTOHSCROLL |
		ES_AUTOVSCROLL, rect.right / 2 - 100, 420, 300, 22, hWnd, (HMENU)ID_ADD_AGE_TEXT, hInst, NULL);
	SendMessage(hAddAgeText, WM_SETFONT, (WPARAM)hFont, NULL);


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