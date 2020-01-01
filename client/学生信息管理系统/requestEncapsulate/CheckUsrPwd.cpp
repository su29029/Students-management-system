//本程序需引用的头文件均在framework.h中
#include "framework.h"
//本程序窗口控件，句柄的ID，函数前向声明，全局变量声明均在resource.h中
#include "resource.h"

//检查用户名密码
int CheckUsrPwd(char* username, char* password) {
	InitSocketClient((char*)IP, PORT);
	memset(sendBuff, '\0', MAX_BUFF);
	strcat_s(sendBuff, "index=CheckUsrPwd");//识别码，判断是哪种数据包（登录/查询信息/修改信息）
	strcat_s(sendBuff, "&");
	strcat_s(sendBuff, "username=");
	strcat_s(sendBuff, username);
	strcat_s(sendBuff, "&");
	strcat_s(sendBuff, "password=");
	strcat_s(sendBuff, password);

	sockfd = connect(connfd, (struct sockaddr*) & serverAddr, sizeof(serverAddr));
	if (sockfd != CONNECT_SUCCESS) {
		MessageBox(NULL, TEXT("服务器连接失败"), TEXT(""), MB_OK);
		return STATUS_SERVER_ERROR;
	}
	strcpy_s(sendBuff, Base64Encode((unsigned char*)sendBuff));
	int nBytes = strlen(sendBuff);
	int s = send(connfd, sendBuff, nBytes, 0);
	int r = recv(connfd, receiveBuff, nBytes, 0);
	strcpy_s(receiveBuff, Base64Decode((unsigned char*)receiveBuff));
	if (r == RECEIVE_FAILURE) {
		MessageBox(NULL, TEXT("服务器错误"), TEXT(""), MB_OK);
		closesocket(connfd);
	}
	printf("%s", receiveBuff);
	if (strcmp(receiveBuff, "yes") == COMPARE_STRING_TRUE) {
		MessageBox(NULL, TEXT("登录成功"), TEXT(""), MB_OK);
		return LOGIN_SUCCESS;
	}
	else if (strcmp(receiveBuff, "error") == COMPARE_STRING_TRUE) {
		MessageBox(NULL, TEXT("服务器错误"), TEXT(""), MB_OK);
		return STATUS_SERVER_ERROR;
	}
	else {
		closesocket(connfd);
		MessageBox(NULL, TEXT("学号或密码错误"), TEXT("错误"), MB_OK);
		return LOGIN_FAILURE;
	}
}