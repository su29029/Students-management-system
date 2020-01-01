#include <windows.h>
#define NORMAL_SIZE                     64
#define MAX_LOADSTRING     100
#define MAX_BUFF           20480
HINSTANCE                  hInst;                                    // 当前实例
WCHAR                      szTitle[MAX_LOADSTRING];                  // 标题栏文本
WCHAR                      szWindowClass[MAX_LOADSTRING];            // 主窗口类名
RECT                       rect;									 // 窗口矩形

HFONT               hFontTitle;       // title字体
HFONT               hFontFooter;      // footer字体
HFONT               hFont;            // 普通文本字体
HBRUSH              hBrush;           // 画刷

									  // 返回主界面按钮句柄
HWND                    hReturn;

// 登录后主界面控件句柄			   
HWND					   hSearch;
HWND					   hResize;
HWND					   hAdd;
HWND					   hDelete;

// 登陆界面控件句柄
HWND					   hTitle;
HWND					   hUsername;
HWND					   hPassword;
HWND					   hFooter;
HWND					   hLogin;
HWND					   hRegister;
HWND					   hLoginText;
HWND					   hPasswordText;

// 查询信息界面控件句柄
HWND					   hSearchUsername;
HWND					   hSearchText;
HWND					   hSearchButton;

// 修改信息-查询界面控件句柄
HWND		    		   hResizeUsername;
HWND					   hResizeText;
HWND					   hResizeButton;

// 修改信息-修改界面控件句柄
HWND					   hResizeSettingName;
HWND					   hResizeSettingSex;
HWND					   hResizeSettingAge;
HWND					   hResizeSettingMajor;
HWND					   hResizeSettingGrade;
HWND					   hResizeSettingMidTermScore;
HWND					   hResizeSettingFinalTermScore;
HWND					   hResizeNameText;
HWND					   hResizeSexText;
HWND					   hResizeAgeText;
HWND					   hResizeGradeText;
HWND					   hResizeMajorText;
HWND					   hResizeMidText;
HWND					   hResizeFinalText;
HWND					   hResizeSettingButton;

// 添加信息页面控件句柄
HWND				       hAddID;
HWND					   hAddIDText;
HWND					   hAddPassword;
HWND					   hAddPasswordText;
HWND					   hAddName;
HWND					   hAddNameText;
HWND					   hAddSex;
HWND					   hAddSexText;
HWND					   hAddMajor;
HWND					   hAddMajorText;
HWND					   hAddGrade;
HWND					   hAddGradeText;
HWND					   hAddAge;
HWND					   hAddAgeText;
HWND					   hAddButton;

// 删除信息页面控件句柄
HWND					   hDeleteID;
HWND					   hDeleteIDText;
HWND					   hDeleteName;
HWND					   hDeleteNameText;
HWND					   hDeleteButton;

// 用户输入的用户名和密码将存储在这里，并传入服务器端与链表中的内容比较
WCHAR				   username[64];
WCHAR				   password[64];

// 登录状态,默认为未登录
int					   isLogin;


SOCKET                  connfd;                 // 客户端套接字描述符
SOCKET                  sockfd;                 // 服务端套接字描述符
SOCKADDR_IN             serverAddr;             // ip及端口设置
WSADATA                 wsaData;                // winsock
char                    sendBuff[MAX_BUFF];     // 发送数据包
char                    receiveBuff[MAX_BUFF];  // 接受数据包

char					   rseID[NORMAL_SIZE];     // 修改信息时的查询学号
