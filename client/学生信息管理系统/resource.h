//{{NO_DEPENDENCIES}}
// Microsoft Visual C++ 生成的包含文件。
// 供 学生信息管理系统.rc 使用

// 此处定义了窗口句柄及控件的ID,链表,以及函数的前向声明
#ifndef RESOURCE_H
#define RESOURCE_H

#define IDC_MYICON                      2
#define IDD_MY_DIALOG                   102
#define IDS_APP_TITLE                   103
#define IDD_ABOUTBOX                    103
#define IDM_ABOUT                       104
#define IDM_EXIT                        105
#define IDI_MY                          107
#define IDI_SMALL                       108
#define IDC_MY                          109
#define IDR_MAINFRAME                   128
#define IDC_BUTTON1                     1000

#define ID_RETURN                       2000
#define IDBTN_LOG                       3001
#define IDBTN_REG                       3002

#define ID_LOGIN_USERNAME               5001
#define ID_LOGIN_PASSWORD               5002
#define ID_LOGIN_USERNAME_TEXT          5003
#define ID_LOGIN_PASSWORD_TEXT          5004

#define ID_BIG_TITLE                    6000

#define ID_FOOTER                       8000

#define ID_SEARCH_USERNAME_TEXT         9000
#define ID_SEARCH_USERNAME              9001
#define ID_SEARCH_ACK                   9002

#define ID_RESIZE_USERNAME              10001    
#define ID_RESIZE_TEXT				    10002
#define ID_RESIZE_ACK                   10003

#define ID_RESIZE_SETTING_NAME_TEXT     10004
#define ID_RESIZE_SETTING_NAME          10005
#define ID_RESIZE_SETTING_SEX_TEXT      10006
#define ID_RESIZE_SETTING_SEX           10007
#define ID_RESIZE_SETTING_MAJOR_TEXT    10008
#define ID_RESIZE_SETTING_MAJOR         10009
#define ID_RESIZE_SETTING_GRADE         10010
#define ID_RESIZE_SETTING_GRADE_TEXT    10011
#define ID_RESIZE_SETTING_AGE_TEXT      10012
#define ID_RESIZE_SETTING_AGE           10013
#define ID_RESIZE_SETTING_MID			10014
#define ID_RESIZE_SETTING_MID_TEXT		10015
#define ID_RESIZE_SETTING_FINAL         10016
#define ID_RESIZE_SETTING_FINAL_TEXT    10017
#define ID_RESIZE_SETTING_ACK           10018


#define ID_ADD_ID                       10101
#define ID_ADD_ID_TEXT                  10102
#define ID_ADD_NAME                     10103
#define ID_ADD_NAME_TEXT                10104
#define ID_ADD_SEX                      10105 
#define ID_ADD_SEX_TEXT                 10106
#define ID_ADD_MAJOR                    10107
#define ID_ADD_MAJOR_TEXT               10108
#define ID_ADD_AGE                      10109
#define ID_ADD_AGE_TEXT                 10110
#define ID_ADD_GRADE                    10111
#define ID_ADD_GRADE_TEXT               10112
#define ID_ADD_PASSWORD                 10113
#define ID_ADD_PASSWORD_TEXT            10114
#define ID_ADD_ACK                      10115



#define ID_DELETE_ID                    10201
#define ID_DELETE_ID_TEXT               10202
#define ID_DELETE_NAME                  10203
#define ID_DELETE_NAME_TEXT             10204
#define ID_DELETE_ACK                   10205


#define ID_SEARCH                       32775
#define ID_RESIZE                       32776
#define ID_ADD                          32779
#define ID_DELETE                       32780
#define ID_LOG_OFF                      32781
#define ID_BACK_TO_INDEX                32785

#define IDC_STATIC                      -1



#define PORT                            7546
#define IP                              "127.0.0.1" //"45.76.155.133"



#define SMALL_SIZE                      8
#define NORMAL_SIZE                     64
#define BIG_SIZE                        256

#define STATUS_LOGIN_YES			    1
#define STATUS_LOGIN_NO                 0
#define STATUS_LOGIN_USRPWD_ERROR       1

#define SEARCH_FOR_SEARCH               0
#define SEARCH_FOR_RESIZE               1
#define SEARCH_FOR_DELETE               1

#define COMPARE_STRING_TRUE             0

#define NAME_MAXIMUM                    32
#define NAME_MINIMUM                    4
#define USERNAME_LENGTH                 13
#define PASSWORD_MAXIMUM                18
#define PASSWORD_MINIMUM                6


#define LOGIN_ACK				        0
#define SEARCH_ACK                      0
#define RESIZE_ACK                      0
#define ADD_ACK                         0
#define DELETE_ACK                      0



#define STATUS_SERVER_ERROR            -1
#define INITIAL_SOCKET_ERROR           -1
#define CONNECT_SUCCESS                 0
#define CONNECT_FAILURE                 0
#define RECEIVE_SUCCESS                 0
#define RECEIVE_FAILURE                -1
#define LOGIN_SUCCESS                   0
#define LOGIN_FAILURE                   1

#define SEARCH_FAILURE                  1
#define RESIZE_FAILURE                  1
#define ADD_FAILURE                     1
#define DELETE_FAILURE                  1

typedef struct JSON_KEY {		//键
	char key[NORMAL_SIZE];
	struct JSON_KEY* nextk;
}JSONKEY;

typedef struct JSON_VALUE {		//值
	char value[NORMAL_SIZE];
	struct JSON_VALUE* nextv;
}JSONVALUE;

typedef struct JSON {			//组键值对
	JSONKEY* key;
	JSONVALUE* value;
}JSON;


#define MAX_LOADSTRING     100
#define MAX_BUFF           20480

extern HINSTANCE                  hInst;                                    // 当前实例
extern WCHAR                      szTitle[MAX_LOADSTRING];                  // 标题栏文本
extern WCHAR                      szWindowClass[MAX_LOADSTRING];            // 主窗口类名
extern RECT                       rect;									 // 窗口矩形

extern HFONT               hFontTitle;       // title字体
extern HFONT               hFontFooter;      // footer字体
extern HFONT               hFont;            // 普通文本字体
extern HBRUSH              hBrush;           // 画刷

// 返回主界面按钮句柄
extern HWND                    hReturn;

// 登录后主界面控件句柄			   
extern HWND					   hSearch;
extern HWND					   hResize;
extern HWND					   hAdd;
extern HWND					   hDelete;

// 登陆界面控件句柄
extern HWND					   hTitle;
extern HWND					   hUsername;
extern HWND					   hPassword;
extern HWND					   hFooter;
extern HWND					   hLogin;
extern HWND					   hRegister;
extern HWND					   hLoginText;
extern HWND					   hPasswordText;

// 查询信息界面控件句柄
extern HWND					   hSearchUsername;
extern HWND					   hSearchText;
extern HWND					   hSearchButton;

// 修改信息-查询界面控件句柄
extern HWND		    		   hResizeUsername;
extern HWND					   hResizeText;
extern HWND					   hResizeButton;

// 修改信息-修改界面控件句柄
extern HWND					   hResizeSettingName;
extern HWND					   hResizeSettingSex;
extern HWND					   hResizeSettingAge;
extern HWND					   hResizeSettingMajor;
extern HWND					   hResizeSettingGrade;
extern HWND					   hResizeSettingMidTermScore;
extern HWND					   hResizeSettingFinalTermScore;
extern HWND					   hResizeNameText;
extern HWND					   hResizeSexText;
extern HWND					   hResizeAgeText;
extern HWND					   hResizeGradeText;
extern HWND					   hResizeMajorText;
extern HWND					   hResizeMidText;
extern HWND					   hResizeFinalText;
extern HWND					   hResizeSettingButton;

// 添加信息页面控件句柄
extern HWND				       hAddID;
extern HWND					   hAddIDText;
extern HWND					   hAddPassword;
extern HWND					   hAddPasswordText;
extern HWND					   hAddName;
extern HWND					   hAddNameText;
extern HWND					   hAddSex;
extern HWND					   hAddSexText;
extern HWND					   hAddMajor;
extern HWND					   hAddMajorText;
extern HWND					   hAddGrade;
extern HWND					   hAddGradeText;
extern HWND					   hAddAge;
extern HWND					   hAddAgeText;
extern HWND					   hAddButton;

// 删除信息页面控件句柄
extern HWND					   hDeleteID;
extern HWND					   hDeleteIDText;
extern HWND					   hDeleteName;
extern HWND					   hDeleteNameText;
extern HWND					   hDeleteButton;

// 用户输入的用户名和密码将存储在这里，并传入服务器端与链表中的内容比较
extern WCHAR				   username[64];
extern WCHAR				   password[64];

// 登录状态,默认为未登录
extern int					   isLogin;


extern SOCKET                  connfd;                 // 客户端套接字描述符
extern SOCKET                  sockfd;                 // 服务端套接字描述符
extern SOCKADDR_IN             serverAddr;             // ip及端口设置
extern WSADATA                 wsaData;                // winsock
extern char                    sendBuff[MAX_BUFF];     // 发送数据包
extern char                    receiveBuff[MAX_BUFF];  // 接受数据包

extern char					   rseID[NORMAL_SIZE];     // 修改信息时的查询学号

// 函数的前向声明          

/*
	函数名：MyRegisterClass
	参数：hInstance 当前应用程序实例的句柄
	功能：注册程序主窗口
	返回值：RegisterClassExW(&wcex):为随后在CreateWindow函数中使用的窗口注册一个窗口类
*/
ATOM					   MyRegisterClass(HINSTANCE);



/*
	函数名：InitInstance
	参数：hInstance 当前应用程序实例的句柄；nCmdShow 主窗口显示方式
	功能：保存实例句柄，创建主窗口
	返回值：BOOL类型，创建成功返回true，创建失败返回false
*/
BOOL	                   InitInstance(HINSTANCE, int);



/*
	函数名：CALLBACK WndProc
	参数：hWnd 主窗口句柄；message 系统传递给应用程序的消息；
	wParam 消息参数；lParam 消息参数
	功能：处理主窗口消息
	返回值：0
*/
LRESULT CALLBACK	       WndProc(HWND, UINT, WPARAM, LPARAM);



/*
	函数名：CALLBACK About
	参数：hWnd 主窗口句柄；message 系统传递给应用程序的消息；
	wParam 消息参数；lParam 消息参数
	功能：“关于”框体的消息处理
	返回值：INT_PTR类型（0或1，INT_PTR类型是为了兼容32位和64位编译器设置的）
*/
INT_PTR CALLBACK	       About(HWND, UINT, WPARAM, LPARAM);



/*
	函数名：EnableMenu
	参数：hWnd 主窗口句柄
	功能：使菜单栏目录可用（登录之后）
	返回值：空
*/
void	                   EnableMenu(HWND);



/*
	函数名：DisableMenu
	参数：hWnd主窗口句柄
	功能：使菜单栏目录不可用（未登录状态，退出登录状态）
	返回值：空
*/
void	                   DisableMenu(HWND);


/*
	函数名：DestoryAll
	参数：hWnd主窗口句柄
	功能：将主窗口所有控件移除（重绘窗口时）
	返回值：空
*/
void	                   DestroyAll();


/*
	函数名：SetMainPage
	参数：hWnd主窗口句柄
	功能：粉刷渲染用户登录后的主界面
	返回值：空
*/
void	                   SetMainPage(HWND);


/*
	函数名：SetLoginPage
	参数：hWnd主窗口句柄
	功能：粉刷渲染登录界面
	返回值：空
*/
void	                   SetLoginPage(HWND);


/*
	函数名：SetSearchPage
	参数：hWnd主窗口句柄
	功能：粉刷渲染搜索信息界面
	返回值：空
*/
void	                   SetSearchPage(HWND);


/*
	函数名：SetResizePage
	参数：hWnd主窗口句柄
	功能：粉刷渲染修改-输入修改目标界面
	返回值：空
*/
void	                   SetResizePage(HWND);


/*
	函数名：SetResizePageSetting
	参数：hWnd主窗口句柄
	功能：粉刷渲染修改查询界面
	返回值：空
*/
void	                   SetResizeSettingPage(HWND);


/*
	函数名：SetAddPage
	参数：hWnd主窗口句柄
	功能：粉刷渲染录入信息界面
	返回值：空
*/
void	                   SetAddPage(HWND);


/*
	函数名：SetDeletePage
	参数：hWnd主窗口句柄
	功能：粉刷渲染删除信息界面
	返回值：空
*/
void	                   SetDeletePage(HWND);


/*
	函数名：CheckUserPwd
	参数：username,password
	功能：判断用户名密码是否正确
	返回值：-1，0，1
*/
int                        CheckUsrPwd(char*, char*);


/*
	函数名：Search
	参数：username，code i(用于判断此时函数的用法)
	功能：实现在链表中搜索一个结点，然后利于其他函数修改或删除
	返回值：Receivebuff
*/
char* Search(char*, int);


/*
	函数名：Resize
	参数：username,name, sex, major, grade,  age, mid-score, final-score
	功能：实现修改学生信息，不能修改username和password，但可以增添期中和期末成绩
	返回值：-1，0，1
*/
int						   Resize(char*, char*, char*, char*, char*, char*, char*, char*);


/*
	函数名：Add
	参数：username 学号, password 密码, name 姓名, sex 性别, major 专业, grade 年级, age 年龄
	功能：实现添加学生信息到Student链表中
	返回值：-1，0，1
*/
int					       Add(char*, char*, char*, char*, char*, char*, char*);


/*
	函数名：Delete
	参数：username 学号,name 姓名
	功能：删除链表某结点，即删除某学生信息
	返回值：-1，0，1
*/
int						   Delete(char*, char*);


/*
	函数名：InitSocketClient
	参数：ip IP地址，port 端口
	功能：初始化套接字
	返回值：空
*/
void					   InitSocketClient(char*, int);


/*
	函数名：ParseReceive
	参数：ReceiveBuff 从服务端传来的数据包
	功能：解析服务器的回返数据包为类json格式，存入两个缓冲链表中
	返回值：JSON类型，缓冲链表索引
*/
JSON* ParseReceive(char*);


/*
	函数名：Base64Encode
	参数：str 欲base64编码的字符串
	功能：将字符串进行base64编码
	返回值：编码后的字符串
*/
char* Base64Encode(unsigned char*);


/*
	函数名：Base64Encode
	参数：str 欲base64编码的字符串
	功能：将字符串进行base64编码
	返回值：编码后的字符串
*/
char* Base64Decode(unsigned char*);

#endif
// Next default values for new objects
// 
#ifdef APSTUDIO_INVOKED
#ifndef APSTUDIO_READONLY_SYMBOLS
#define _APS_NO_MFC                     1
#define _APS_NEXT_RESOURCE_VALUE        129
#define _APS_NEXT_COMMAND_VALUE         32786
#define _APS_NEXT_CONTROL_VALUE         1001
#define _APS_NEXT_SYMED_VALUE           110
#endif
#endif
