//本程序需引用的头文件均在framework.h中
#include "../framework.h"
//本程序窗口控件，句柄的ID，函数前向声明，全局变量声明均在resource.h中
#include "../resource.h"
//删除（删）
int Delete(char* username, char* name) {
	memset(sendBuff, '\0', sizeof(sendBuff));
	strcat_s(sendBuff, "index=Delete");
	strcat_s(sendBuff, "&");
	strcat_s(sendBuff, "username=");
	strcat_s(sendBuff, username);
	strcat_s(sendBuff, "&");
	strcat_s(sendBuff, "name=");
	strcat_s(sendBuff, name);

	InitSocketClient((char*)IP, PORT);
	sockfd = connect(connfd, (struct sockaddr*) & serverAddr, sizeof(serverAddr));
	if (sockfd != CONNECT_FAILURE) {
		return STATUS_SERVER_ERROR;
	}
	strcpy_s(sendBuff, Base64Encode((unsigned char*)sendBuff));
	int nBytes = strlen(sendBuff);
	int s = send(connfd, sendBuff, nBytes, 0);
	int r = recv(connfd, receiveBuff, nBytes, 0);
	strcpy_s(receiveBuff, Base64Decode((unsigned char*)receiveBuff));
	if (r == RECEIVE_FAILURE) {
		closesocket(connfd);
		return STATUS_SERVER_ERROR;
	}
	if (strcmp(receiveBuff, "yes") == COMPARE_STRING_TRUE) {
		return DELETE_ACK;
	}
	else
		return DELETE_FAILURE;
}