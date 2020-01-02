
//本程序需引用的头文件均在framework.h中
#include "../framework.h"
//本程序窗口控件，句柄的ID，函数前向声明，全局变量声明均在resource.h中
#include "../resource.h"
//初始化套接字
void InitSocketClient(char* ip, int port) {

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		perror("Error in initialing socket.");
		MessageBox(NULL, TEXT("服务器连接失败"), TEXT(""), MB_OK);
		return;
	}
	//创建套接字
	if ((connfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == INITIAL_SOCKET_ERROR) {
		perror("Error in initialing socket.\n in socket().");
		MessageBox(NULL, TEXT("服务器连接失败"), TEXT(""), MB_OK);
		return;
	}
	//设置参数
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(port);

	inet_pton(AF_INET, ip, &serverAddr.sin_addr);
}