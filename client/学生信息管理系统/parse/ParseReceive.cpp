//本程序需引用的头文件均在framework.h中
#include "../framework.h"
//本程序窗口控件，句柄的ID，函数前向声明，全局变量声明均在resource.h中
#include "../resource.h"
//解析服务端回返字符串
JSON* ParseReceive(char* receiveBuff) {
	//解析客户端传来的字符串并存入链表
	JSON* json;
	json = (JSON*)malloc(sizeof(JSON));
	if (json == NULL) {
		exit(-1);
	}
	int start = 0;
	int length = strlen(receiveBuff);
	JSONKEY* headk, * nodek, * endk;
	JSONVALUE* headv, * nodev, * endv;
	headk = (JSONKEY*)malloc(sizeof(JSONKEY));
	if (headk == NULL) {
		exit(-1);
	}
	headv = (JSONVALUE*)malloc(sizeof(JSONVALUE));
	if (headv == NULL) {
		exit(-1);
	}
	endk = headk;
	endv = headv;

	for (int idx = 0; idx <= length; idx++) {
		if (receiveBuff[idx] == '=') {
			//strcat(nodek->key,&(receiveBuff[j])); 
			//printf("%c\n",receiveBuff[start]);
			nodek = (JSONKEY*)malloc(sizeof(JSONKEY));
			if (nodek == NULL) {
				exit(-1);
			}
			memset(nodek->key, '\0', sizeof(nodek));
			strncpy_s(nodek->key, receiveBuff + start, idx - start);
			printf("%s\n", nodek->key);
			start = idx + 1;
			endk->nextk = nodek;
			endk = nodek;
		}
		else if (receiveBuff[idx] == '&' || receiveBuff[idx] == '\0') {
			//strcat(nodev->value,&(receiveBuff[j]));
			//printf("%c\n",receiveBuff[start]);
			nodev = (JSONVALUE*)malloc(sizeof(JSONVALUE));
			if (nodev == NULL) {
				exit(-1);
			}
			memset(nodev->value, '\0', sizeof(nodev));
			strncpy_s(nodev->value, receiveBuff + start, idx - start);
			start = idx + 1;
			printf("%s\n", nodev->value);
			endv->nextv = nodev;
			endv = nodev;
		}
	}
	endk->nextk = NULL;
	endv->nextv = NULL;
	json->key = headk;
	json->value = headv;
	return json;
}