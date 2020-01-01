	//*****************************学生信息管理系统**********************************
	//Win32 for the students' information management system
	//Language:C/C++
	//Author:SYQ HQ WYQ
	//Date:2019-12-18
	//Description:Client of the students' information management system

	//本程序需引用的头文件均在framework.h中
	#include "framework.h"
	//本程序窗口控件，句柄的ID，函数前向声明，全局变量声明均在resource.h中
	#include "resource.h"
	#pragma comment(lib,"WS2_32")
	//主函数wWinMain
	int APIENTRY wWinMain(
		_In_ HINSTANCE hInstance,
		_In_opt_ HINSTANCE hPrevInstance,
		_In_ LPWSTR    lpCmdLine,
		_In_ int       nCmdShow) {

		UNREFERENCED_PARAMETER(hPrevInstance);
		UNREFERENCED_PARAMETER(lpCmdLine);

		// 初始化全局字符串 
		LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
		LoadStringW(hInstance, IDC_MY, szWindowClass, MAX_LOADSTRING);
		MyRegisterClass(hInstance);

		memset(receiveBuff, '\0', sizeof(receiveBuff));
		isLogin = 0;
		// 初始化应用程序
		if (!InitInstance(hInstance, nCmdShow))
		{
			return FALSE;
		}

		HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY));

		MSG msg;

		// 主消息循环
		while (GetMessage(&msg, nullptr, 0, 0))
		{
			if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		return (int)msg.wParam;
	}

	//注册窗口类
	ATOM MyRegisterClass(HINSTANCE hInstance) {
	WNDCLASSEXW wcex;

	wcex.cbSize                       = sizeof(WNDCLASSEX);
	wcex.style                        = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc                  = WndProc;
	wcex.cbClsExtra                   = 0;
	wcex.cbWndExtra                   = 0;
	wcex.hInstance                    = hInstance;
	wcex.hIcon                        = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY));
	wcex.hCursor                      = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground                = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName                 = MAKEINTRESOURCEW(IDC_MY);
	wcex.lpszClassName                = szWindowClass;
	wcex.hIconSm                      = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}

	//保存实例句柄，创建主窗口
	BOOL InitInstance(HINSTANCE hInstance, int nCmdShow) {
	hInst = hInstance; // 将实例句柄存储在全局变量中

	HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

	if (!hWnd) {
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

	//处理主窗口的消息
	LRESULT CALLBACK WndProc(
		HWND hWnd,
		UINT message,
		WPARAM wParam,
		LPARAM lParam) {
		GetClientRect(hWnd, &rect);
	
		switch (message){
			case WM_CREATE: {

				SetLoginPage(hWnd);
				//未登录状态，禁用菜单栏
				DisableMenu(hWnd);
				break;
			}
			case WM_SIZE: {
				GetClientRect(hWnd, &rect);
				UpdateWindow(hWnd);
				break;
			}
			case WM_COMMAND: {
			
				int wmId = LOWORD(wParam);

				switch (wmId) {
					case IDM_ABOUT: {   //关于框
						DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
						break;
					}
					case IDM_EXIT: {   //关闭程序
						DestroyWindow(hWnd);
						break;
					}
					case ID_BACK_TO_INDEX: {   //回到主页
						if (isLogin == STATUS_LOGIN_NO) {
							MessageBox(NULL, TEXT("请先登录"), TEXT("提示"), MB_OK);
							SetLoginPage(hWnd);
						}
						else {
							SetMainPage(hWnd);
						}
						break;
					}
					//兼有菜单栏选项 和 mainpage 中的选项
					case ID_SEARCH: {   //搜索
						if (isLogin == STATUS_LOGIN_NO) {
							MessageBox(NULL, TEXT("请先登录"), TEXT("提示"), MB_OK);
							SetLoginPage(hWnd);
						}
						else {
							SetSearchPage(hWnd);
						}
						break;
					}
					case ID_RESIZE: {  //修改
						if (isLogin == STATUS_LOGIN_NO) {
							MessageBox(NULL, TEXT("请先登录"), TEXT("提示"), MB_OK);
							SetLoginPage(hWnd);
						}
						else {
							SetResizePage(hWnd);
						}
						break;
					}
					case ID_ADD: {   //添加
						if (isLogin == STATUS_LOGIN_NO) {
							MessageBox(NULL, TEXT("请先登录"), TEXT("提示"), MB_OK);
							SetLoginPage(hWnd);
						}
						else {
							SetAddPage(hWnd);
						}
						break;

					}
					case ID_DELETE: {   //删除
						if (isLogin == STATUS_LOGIN_NO) {
							MessageBox(NULL, TEXT("请先登录"), TEXT("提示"), MB_OK);
							SetLoginPage(hWnd);
						}
						else {
							SetDeletePage(hWnd);
						}
						break;
					} 
					case ID_LOG_OFF: {   //登出
						if (isLogin == STATUS_LOGIN_NO) {
							MessageBox(NULL, TEXT("您尚未登录"), TEXT("提示"), MB_OK);
							SetLoginPage(hWnd);
						}
						else {
							MessageBox(NULL, TEXT("您已退出登录！"), TEXT("提示"), MB_OK);
							isLogin = STATUS_LOGIN_NO;
							SetLoginPage(hWnd);
						}
						break;
					}
					case IDBTN_LOG: {   //登录确认按钮
						memset(username, '\0', sizeof(username));
						memset(password, '\0', sizeof(password));
						GetWindowText(hLoginText, username, (NORMAL_SIZE) / 2);
						GetWindowText(hPasswordText, password, (NORMAL_SIZE) / 2);
						char usrnm[NORMAL_SIZE];
						char passwd[NORMAL_SIZE];
						sprintf_s(usrnm, "%ws", username);
						sprintf_s(passwd, "%ws", password);
						if (strcmp(usrnm, "") == COMPARE_STRING_TRUE) {
							MessageBox(NULL, TEXT("学号不能为空！"), TEXT(""), MB_OK);
							break;
						}
						else if (strlen(usrnm) != USERNAME_LENGTH) {
							MessageBox(NULL, TEXT("学号格式错误，必须是13位！"), TEXT(""), MB_OK);
							break;
						}
						else if (strcmp(passwd, "") == COMPARE_STRING_TRUE) {
							MessageBox(NULL, TEXT("密码不能为空！"), TEXT(""), MB_OK);
							break;
						}
						else if (strlen(passwd) < PASSWORD_MINIMUM || strlen(passwd) > PASSWORD_MAXIMUM) {
							MessageBox(NULL, TEXT("密码错误，必须为6-18位！"), TEXT(""), MB_OK);
							break;
						}
						else {
							int IsRight = 0;
							IsRight = CheckUsrPwd(usrnm, passwd);
							if (IsRight == LOGIN_ACK) {
								isLogin = STATUS_LOGIN_YES;
								EnableMenu(hWnd);
								SetMainPage(hWnd);
								break;
							}
							else if (IsRight == STATUS_SERVER_ERROR) { //服务器错误
								isLogin = STATUS_LOGIN_NO;
								break;
							}
							else if (IsRight == STATUS_LOGIN_USRPWD_ERROR) { //客户端错误
								isLogin = STATUS_LOGIN_NO;
								SetWindowText(hPasswordText, TEXT(""));
								break;
							}
							else;
						}
						break;
					}
					case IDBTN_REG: {  //注册按钮
						SetAddPage(hWnd);
						break;
					}
					case ID_SEARCH_ACK: {   //搜索确认
						char searchUserName[NORMAL_SIZE];
						//WCHAR SrchUsrNm[NORMAL_SIZE];
						char result[4*BIG_SIZE];
						WCHAR res[BIG_SIZE];
						memset(searchUserName, '\0', sizeof(searchUserName));
						memset(res, '\0', sizeof(res));
						memset(result, '\0', sizeof(result));
						GetWindowTextA(hSearchText, searchUserName, (NORMAL_SIZE) / 2);  //可以获取中文字符
						//sprintf_s(searchUserName, "%ws", SrchUsrNm);
						strcpy_s(result, Search(searchUserName, SEARCH_FOR_SEARCH));
						
						if (strcmp(result, "no") == COMPARE_STRING_TRUE) {
							MessageBox(NULL, TEXT("查询失败：未找到数据"), TEXT("错误"), MB_OK);
							break;
						}
						if (strcmp(result, "connect error") == COMPARE_STRING_TRUE) {
							MessageBox(NULL, TEXT("服务器连接失败"), TEXT("错误"), MB_OK);
							break;
						}
						if (strcmp(result, "receive error") == COMPARE_STRING_TRUE) {
							MessageBox(NULL, TEXT("服务器错误"), TEXT("错误"), MB_OK);
							break;
						}
						if (strcmp(result, "username error") == COMPARE_STRING_TRUE) {
							MessageBox(NULL, TEXT("学号格式错误，必须是13位！"), TEXT(""), MB_OK);
							break;
						}
						else {
							JSON* json = ParseReceive(receiveBuff);
							JSONKEY* hk = json->key;
							JSONVALUE* hv = json->value;
							memset(result, '\0', sizeof(result));
							for (; (hk != NULL) && (hv != NULL); hk = hk->nextk, hv = hv->nextv) {
								if (strcmp(hk->key, "username") == COMPARE_STRING_TRUE) {
									strcat_s(result, "查询到学号");
									strcat_s(result, hv->value);
									strcat_s(result, "的信息：\n");
								}
								else if (strcmp(hk->key, "name") == COMPARE_STRING_TRUE) {
									strcat_s(result, "姓名：");
									strcat_s(result, hv->value);
									strcat_s(result, "\n");
								}
								else if (strcmp(hk->key, "sex") == COMPARE_STRING_TRUE) {
									strcat_s(result, "性别：");
									strcat_s(result, hv->value);
									strcat_s(result, "\n");
								}
								else if (strcmp(hk->key, "major") == COMPARE_STRING_TRUE) {
									strcat_s(result, "专业：");
									strcat_s(result, hv->value);
									strcat_s(result, "\n");
								}
								else if (strcmp(hk->key, "grade") == COMPARE_STRING_TRUE) {
									strcat_s(result, "年级：");
									strcat_s(result, hv->value);
									strcat_s(result, "\n");
								}
								else if (strcmp(hk->key, "age") == COMPARE_STRING_TRUE) {
									strcat_s(result, "年龄：");
									strcat_s(result, hv->value);
									strcat_s(result, "\n");
								}
								else if (strcmp(hk->key, "midTermScore") == COMPARE_STRING_TRUE) {
									strcat_s(result, "期中成绩：");
									strcat_s(result, hv->value);
									strcat_s(result, "\n");
								}
								else if (strcmp(hk->key, "finalTermScore") == COMPARE_STRING_TRUE) {
									strcat_s(result, "期末成绩：");
									strcat_s(result, hv->value);
								}
								else;
							}
							//swprintf_s(res, 256, L"%hs", result);
							MessageBoxA(NULL, result, "结果", MB_OK);
							//MessageBox(NULL, LPTSTR("12"), TEXT("2"), MB_OK);
							break;
						}
					}
					case ID_RESIZE_ACK: {  //修改查询确认按钮
						char resizeUserName[NORMAL_SIZE];
						//WCHAR resizeUserName[NORMAL_SIZE];
						char result[NORMAL_SIZE];
						memset(resizeUserName, '\0', sizeof(resizeUserName));
						GetWindowTextA(hResizeText, resizeUserName, (NORMAL_SIZE) / 2);
						//sprintf_s(RseUsrNm, "%ws", resizeUserName);
						strcpy_s(result, Search(resizeUserName, SEARCH_FOR_RESIZE));
						if (strcmp(result, "no") == COMPARE_STRING_TRUE) {
							MessageBox(NULL, TEXT("查询失败：未找到数据"), TEXT("错误"), MB_OK);
							break;
						}
						else if (strcmp(result, "connect error") == COMPARE_STRING_TRUE) {
							MessageBox(NULL, TEXT("服务器连接失败"), TEXT("错误"), MB_OK);
							break;
						}
						else if (strcmp(result, "receive error") == COMPARE_STRING_TRUE) {
							MessageBox(NULL, TEXT("服务器错误"), TEXT("错误"), MB_OK);
							break;
						}
						else {
							WCHAR resultText[NORMAL_SIZE];
							memset(resultText, '\0', sizeof(resultText));
							swprintf_s(resultText, NORMAL_SIZE, L"查询到%hs的信息", resizeUserName);
							strcpy_s(rseID, resizeUserName);
							MessageBoxEx(NULL, resultText, TEXT("提示"), MB_OK, MAKELANGID(LANG_YI, SUBLANG_YI_PRC));
							SetResizeSettingPage(hWnd);
							break;
						}
					}
					case ID_RESIZE_SETTING_ACK: {   //修改确认按钮
						char resizeName[NORMAL_SIZE];
						//WCHAR RseNm[NORMAL_SIZE];
						char resizeMajor[NORMAL_SIZE];
						//WCHAR RseMj[NORMAL_SIZE];
						char resizeSex[SMALL_SIZE];
						//WCHAR RseSx[SMALL_SIZE];
						char resizeGrade[SMALL_SIZE+3];
						//WCHAR RseGd[SMALL_SIZE];
						char resizeAge[SMALL_SIZE];
						//WCHAR RseAg[SMALL_SIZE];
						char resizeMidTerm[SMALL_SIZE];
						//WCHAR RseMid[SMALL_SIZE];
						char resizeFinalTerm[SMALL_SIZE];
						//WCHAR RseFinal[SMALL_SIZE];
						//memset(RseNm, '\0', sizeof(RseNm));
						//memset(RseSx, '\0', sizeof(RseSx));
						//memset(RseMj, '\0', sizeof(RseMj));
						//memset(RseGd, '\0', sizeof(RseGd));
						//memset(RseAg, '\0', sizeof(RseAg));
						//memset(RseMid, '\0', sizeof(RseMid));
						//memset(RseFinal, '\0', sizeof(RseFinal));
						GetWindowTextA(hResizeNameText, resizeName, NORMAL_SIZE);
						GetWindowTextA(hResizeMajorText, resizeMajor, NORMAL_SIZE);
						GetWindowTextA(hResizeSexText, resizeSex, SMALL_SIZE);
						GetWindowTextA(hResizeGradeText, resizeGrade, SMALL_SIZE+3);
						GetWindowTextA(hResizeAgeText, resizeAge, SMALL_SIZE);
						GetWindowTextA(hResizeMidText, resizeMidTerm, SMALL_SIZE);
						GetWindowTextA(hResizeFinalText, resizeFinalTerm, SMALL_SIZE);
						//sprintf_s(resizeName, "%ws", RseNm);
						//sprintf_s(resizeSex, "%ws", RseSx);
						//sprintf_s(resizeMajor, "%ws", RseMj);
						//sprintf_s(resizeGrade, "%ws", RseGd);
						//sprintf_s(resizeAge, "%ws", RseAg);
						//sprintf_s(resizeMidTerm, "%ws", RseMid);
						//sprintf_s(resizeFinalTerm, "%ws", RseFinal);
						if (strcmp(resizeName, "") == COMPARE_STRING_TRUE) {
							MessageBox(NULL, TEXT("姓名不能为空！"), TEXT("错误"), MB_OK);
							break;
						}
						else if (strcmp(resizeSex, "") == COMPARE_STRING_TRUE) {
							MessageBox(NULL, TEXT("性别不能为空！"), TEXT("错误"), MB_OK);
							break;
						}
						else if (strcmp(resizeMajor, "") == COMPARE_STRING_TRUE) {
							MessageBox(NULL, TEXT("专业不能为空！"), TEXT("错误"), MB_OK);
							break;
						}
						else if (strcmp(resizeGrade, "") == COMPARE_STRING_TRUE) {
							MessageBox(NULL, TEXT("年级不能为空！"), TEXT("错误"), MB_OK);
							break;
						}
						else if (strcmp(resizeAge, "") == COMPARE_STRING_TRUE) {
							MessageBox(NULL, TEXT("年龄不能为空！"), TEXT("错误"), MB_OK);
							break;
						}
						else if (strlen(resizeName) > NAME_MAXIMUM || strlen(resizeName) < NAME_MINIMUM) {
							MessageBox(NULL, TEXT("姓名非法，姓名至少2个字(4位)最多16个字(8位)！"), TEXT("错误"), MB_OK);
							break;
						}
						else if (strcmp(resizeSex, "男") == COMPARE_STRING_TRUE && strcmp(resizeSex, "女") == COMPARE_STRING_TRUE) {
							MessageBox(NULL, TEXT("性别非法"), TEXT("错误"), MB_OK);
							break;
						}
						else if (strcmp(resizeGrade, "大一") == COMPARE_STRING_TRUE && strcmp(resizeGrade, "大二") == COMPARE_STRING_TRUE ||
							strcmp(resizeGrade, "大三") == COMPARE_STRING_TRUE && strcmp(resizeGrade, "大四") == COMPARE_STRING_TRUE) {
							MessageBox(NULL, TEXT("年级非法，必须为“大一”，“大二”，“大三”，“大四”"), TEXT("错误"), MB_OK);
							break;
						}
						else {
							if (MessageBox(NULL, TEXT("确认修改？"), TEXT("提示"), MB_YESNO) == IDYES) {

								int ack = Resize(rseID, resizeName, resizeSex, resizeMajor,
									resizeGrade, resizeAge, resizeMidTerm, resizeFinalTerm);
								if (ack == RESIZE_ACK) {
									MessageBox(NULL, TEXT("已修改！"), TEXT("提示"), MB_OK);
									break;
								}
								else if (ack == STATUS_SERVER_ERROR) {
									MessageBox(NULL, TEXT("服务器错误"), TEXT("错误"), MB_OK);
									break;
								}
								else {
									MessageBox(NULL, TEXT("修改失败"), TEXT("错误"), MB_OK);
									break;
								}
							}
							else
								break;
						}
					}
					case ID_ADD_ACK: {
						char addUserName[NORMAL_SIZE];
						//WCHAR AdUsrNm[NORMAL_SIZE];
						char addPassword[NORMAL_SIZE];
						//WCHAR AdPasswd[NORMAL_SIZE];
						char addName[NORMAL_SIZE];
						//WCHAR AdNm[NORMAL_SIZE];
						char addMajor[NORMAL_SIZE];
						//WCHAR AdMj[NORMAL_SIZE];
						char addSex[SMALL_SIZE];
						//WCHAR AdSx[SMALL_SIZE];
						char addAge[SMALL_SIZE];
						//WCHAR AdAg[SMALL_SIZE];
						char addGrade[SMALL_SIZE+3];
						//WCHAR AdGd[SMALL_SIZE];
						//memset(AdUsrNm, '\0', sizeof(AdUsrNm));
						//memset(AdPasswd, '\0', sizeof(AdPasswd));
						//memset(AdNm, '\0', sizeof(AdNm));
						//memset(AdSx, '\0', sizeof(AdSx));
						//memset(AdMj, '\0', sizeof(AdMj));
						//memset(AdAg, '\0', sizeof(AdAg));
						//memset(AdGd, '\0', sizeof(AdGd));
						GetWindowTextA(hAddIDText, addUserName, NORMAL_SIZE);
						GetWindowTextA(hAddPasswordText, addPassword, NORMAL_SIZE);
						GetWindowTextA(hAddNameText, addName, NORMAL_SIZE);
						GetWindowTextA(hAddMajorText, addMajor, NORMAL_SIZE);
						GetWindowTextA(hAddSexText, addSex, SMALL_SIZE);
						GetWindowTextA(hAddAgeText, addAge, SMALL_SIZE);
						GetWindowTextA(hAddGradeText, addGrade, SMALL_SIZE+3);
						//sprintf_s(addUserName, "%ws", AdUsrNm);
						//sprintf_s(addPassword, "%ws", AdPasswd);
						//sprintf_s(addName, "%ws", AdNm);
						//sprintf_s(addSex, "%ws", AdSx);
						//sprintf_s(addMajor, "%ws", AdMj);
						//sprintf_s(addAge, "%ws", AdAg);
						//sprintf_s(addGrade, "%ws", AdGd);
						
						if (strcmp(addUserName, "") == COMPARE_STRING_TRUE) {
							MessageBox(NULL, TEXT("学号不能为空！"), TEXT("错误"), MB_OK);
							break;
						}
						else if (strcmp(addPassword, "") == COMPARE_STRING_TRUE) {
							MessageBox(NULL, TEXT("密码不能为空！"), TEXT("错误"), MB_OK);
							break;
						}
						else if (strcmp(addName, "") == COMPARE_STRING_TRUE) {
							MessageBox(NULL, TEXT("姓名不能为空！"), TEXT("错误"), MB_OK);
							break;
						}
						else if (strcmp(addSex, "") == COMPARE_STRING_TRUE) {
							MessageBox(NULL, TEXT("性别不能为空！"), TEXT("错误"), MB_OK);
							break;
						}
						else if (strcmp(addMajor, "") == COMPARE_STRING_TRUE) {
							MessageBox(NULL, TEXT("专业不能为空！"), TEXT("错误"), MB_OK);
							break;
						}
						else if (strcmp(addGrade, "") == COMPARE_STRING_TRUE) {
							MessageBox(NULL, TEXT("年级不能为空！"), TEXT("错误"), MB_OK);
							break;
						}
						else if (strcmp(addAge, "") == COMPARE_STRING_TRUE) {
							MessageBox(NULL, TEXT("年龄不能为空！"), TEXT("错误"), MB_OK);
							break;
						}
						else if (strlen(addUserName) != USERNAME_LENGTH) {
							MessageBox(NULL, TEXT("学号非法，必须为13位！"), TEXT("错误"), MB_OK);
							break;
						}
						else if (strlen(addPassword) < PASSWORD_MINIMUM || strlen(addPassword) > PASSWORD_MAXIMUM) {
							MessageBox(NULL, TEXT("密码非法，必须位6-18位之间"), TEXT("错误"), MB_OK);
							break;
						}
						else if (strlen(addName) > NAME_MAXIMUM || strlen(addName) < NAME_MINIMUM) {
							MessageBox(NULL, TEXT("姓名非法，姓名至少2个字(4位)最多16个字(8位)！"), TEXT("错误"), MB_OK);
							break;
						}
						else if (strcmp(addSex, "男") == COMPARE_STRING_TRUE && strcmp(addSex, "女") == COMPARE_STRING_TRUE) {  //跨平台编码问题，暂时不支持中文
							MessageBox(NULL, TEXT("性别非法"), TEXT("错误"), MB_OK);
							break;
						}
						else if (strcmp(addGrade, "大一") == COMPARE_STRING_TRUE && strcmp(addGrade, "大二") == COMPARE_STRING_TRUE &&
							strcmp(addGrade, "大三") == COMPARE_STRING_TRUE && strcmp(addGrade, "大四") == COMPARE_STRING_TRUE) {
							MessageBox(NULL, TEXT("年级非法，请输入大一，大二，大三或大四。"), TEXT("错误"), MB_OK);
							break;
						}
						else {

							if (MessageBox(NULL, TEXT("确认添加？"), TEXT("提示"), MB_YESNO) == IDYES) {
								int ack = Add(addUserName, addPassword, addName, addSex, addMajor, addGrade, addAge);
								if (ack == ADD_ACK) {
									MessageBox(NULL, TEXT("成功！"), TEXT("提示"), MB_OK);
									//SetLoginPage(hWnd);
									break;
								}
								else if (ack == STATUS_SERVER_ERROR) {
									MessageBox(NULL, TEXT("服务器错误"), TEXT("错误"), MB_OK);
									break;
								}
								else {
									MessageBox(NULL, TEXT("添加失败"), TEXT("错误"), MB_OK);
									break;
								}
							}
							else
								break;
						}
					}
					case ID_DELETE_ACK: {
						char deleteUserName[NORMAL_SIZE];
						//WCHAR DelUsrNm[NORMAL_SIZE];
						char deleteName[NORMAL_SIZE];
						//WCHAR DelNm[NORMAL_SIZE];
						char result[BIG_SIZE];
						//memset(DelUsrNm, '\0', sizeof(DelUsrNm));
						//memset(DelNm, '\0', sizeof(DelNm));
						GetWindowTextA(hDeleteIDText, deleteUserName, NORMAL_SIZE / 2);
						GetWindowTextA(hDeleteNameText, deleteName, NORMAL_SIZE / 2);
						//sprintf_s(deleteUserName, "%ws", DelUsrNm);
						//sprintf_s(deleteName, "%ws", DelNm);
						if (strlen(deleteUserName) != USERNAME_LENGTH) {
							MessageBox(NULL, TEXT("学号不合法，必须是13位！"), TEXT("错误"), MB_OK);
							break;
						}
						else if (strlen(deleteName) > NAME_MAXIMUM || strlen(deleteName) < NAME_MINIMUM) {
							MessageBox(NULL, TEXT("姓名非法，必须是2个字(4位)至16个字(32位)之间！"), TEXT("错误"), MB_OK);
							break;
						}
						else {
							strcpy_s(result, Search(deleteUserName, SEARCH_FOR_DELETE));
							if (strcmp(result, "no") == COMPARE_STRING_TRUE) {
								MessageBox(NULL, TEXT("删除失败：未找到数据"), TEXT("错误"), MB_OK);
								break;
							}
							else if (strcmp(result, "connect error") == COMPARE_STRING_TRUE) {
								MessageBox(NULL, TEXT("服务器连接失败"), TEXT("错误"), MB_OK);
								break;
							}
							else if (strcmp(result, "receive error") == COMPARE_STRING_TRUE) {
								MessageBox(NULL, TEXT("服务器错误"), TEXT("错误"), MB_OK);
								break;
							}
							else {
								if (MessageBox(NULL, TEXT("确认删除？"), TEXT("提示"), MB_YESNO) == IDYES) {
									int ack = Delete(deleteUserName, deleteName);
									if (ack == DELETE_ACK) {
										MessageBox(NULL, TEXT("已删除！"), TEXT("提示"), MB_OK);
										break;
									}
									else if (ack == STATUS_SERVER_ERROR) {
										MessageBox(NULL, TEXT("服务器错误"), TEXT("错误"), MB_OK);
										break;
									}
									else {
										MessageBox(NULL, TEXT("删除失败"), TEXT("错误"), MB_OK);
										break;
									}
								}
								else
									break;
							}
						}
					}
					case ID_RETURN: {
						if (isLogin == STATUS_LOGIN_YES) {
							SetMainPage(hWnd);
						}
						else {
							SetLoginPage(hWnd);
						}
						break;
					}
					default: {
						return DefWindowProc(hWnd, message, wParam, lParam);
					}
				}
			}
			case WM_PAINT: {
				PAINTSTRUCT ps;
				BeginPaint(hWnd, &ps);
				EndPaint(hWnd, &ps);
				break;
			}
			case WM_DESTROY: {
				PostQuitMessage(0);
				break;
			}
			default: {
				return DefWindowProc(hWnd, message, wParam, lParam);
			}
		}
		return 0;
	}

	//“关于”框
	INT_PTR CALLBACK About(
		HWND hDlg,
		UINT message,
		WPARAM wParam,
		LPARAM lParam){
		UNREFERENCED_PARAMETER(lParam);
		switch (message){
			case WM_INITDIALOG: {
				return (INT_PTR)TRUE;
			}
			case WM_COMMAND: {
				if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL){
					EndDialog(hDlg, LOWORD(wParam));
					return (INT_PTR)TRUE;
				}
				break;
			}			   
		}
		return (INT_PTR)FALSE;
	}

	 