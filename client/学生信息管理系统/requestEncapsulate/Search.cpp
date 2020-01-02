//本程序需引用的头文件均在framework.h中
#include "../framework.h"
//本程序窗口控件，句柄的ID，函数前向声明，全局变量声明均在resource.h中
#include "../resource.h"
//搜索（查）
char* Search(char* username, int IsTrueSearch) {
	if (strlen(username) != USERNAME_LENGTH) {
		return (char*)"username error";
	}
	memset(sendBuff, '\0', sizeof(sendBuff));
	strcat_s(sendBuff, "index=Search");
	strcat_s(sendBuff, "&");
	strcat_s(sendBuff, "username=");
	strcat_s(sendBuff, username);
	InitSocketClient((char*)IP, PORT);
	sockfd = connect(connfd, (struct sockaddr*) & serverAddr, sizeof(serverAddr));
	if (sockfd != CONNECT_FAILURE) {
		return (char*)"connect error";
	}
	strcpy_s(sendBuff, Base64Encode((unsigned char*)sendBuff));
	int nBytes = strlen(sendBuff);
	int s = send(connfd, sendBuff, nBytes, 0);
	int r = recv(connfd, receiveBuff, BIG_SIZE, 0);
	strcpy_s(receiveBuff, Base64Decode((unsigned char*)receiveBuff));
	if (r == RECEIVE_FAILURE) {
		closesocket(connfd);
		return (char*)"receive error";
	}
	if (strcmp(receiveBuff, "username_not_found") == COMPARE_STRING_TRUE) {
		return (char*)"no";
	}
	//MessageBoxA(NULL, receiveBuff, "", MB_OK);
	//printf("%s", receiveBuff);
	JSON* json = ParseReceive(receiveBuff);

	JSONKEY* hk = json->key;
	JSONVALUE* hv = json->value;
	if (IsTrueSearch == SEARCH_FOR_RESIZE || IsTrueSearch == SEARCH_FOR_DELETE) {
		for (; (hk != NULL) && (hv != NULL); hk = hk->nextk, hv = hv->nextv) {
			if (strcmp(hk->key, "username") == COMPARE_STRING_TRUE) {
				memset(receiveBuff, '\0', sizeof(receiveBuff));
				strcpy_s(receiveBuff, hv->value);
				return receiveBuff;
			}
		}
	}
	else
		return receiveBuff;
}