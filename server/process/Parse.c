#include <concurrent.h>

Json* ParseReceive(char* receiveBuff){  //解析客户端传来的字符串并存入链表
    Json* json;  //用于获取缓冲链表中的数据
    json = (Json*)malloc(sizeof(Json));
    if (json == NULL){
        exit(-1);
    }
    memset(json, 0, sizeof(Json));
  
    JsonKey *headk,*nodek,*endk;
    JsonValue *headv,*nodev,*endv;
    headk = (JsonKey*)malloc(sizeof(JsonKey));
    if (headk == NULL){
        exit(-1);
    }
    headv = (JsonValue*)malloc(sizeof(JsonValue));
    if (headv == NULL) {
        exit(-1);
	}
    endk = headk;
    endv = headv;

    int start = 0;
    for (int idx = 0;idx <= strlen(receiveBuff);idx++){  //拆分查询字符串
        if (receiveBuff[idx] == '='){
            nodek = (JsonKey*)malloc(sizeof(JsonKey));
            if (nodek == NULL){
                exit(-1);
            }
            memset(nodek,'\0',sizeof(JsonKey));
            strncpy(nodek->key,receiveBuff+start,idx-start);         
            //printf("%s:",nodek->key);
            start = idx + 1;
            endk->nextk = nodek;
            endk = nodek;
        }
        else if (receiveBuff[idx] == '&'||receiveBuff[idx] == '\0'){
            nodev = (JsonValue*)malloc(sizeof(JsonValue));
            if (nodev == NULL){
                exit(-1);
            }
            memset(nodev,0,sizeof(JsonValue));
            strncpy(nodev->value,receiveBuff+start,idx-start);  
            start = idx + 1;
            //printf("%s\n",nodev->value);
            endv->nextv = nodev;
            endv = nodev;
        }
    }
    endk->nextk = NULL;
    endv->nextv = NULL;
    json->key = headk;
    json->value = headv;
    return json;     //将两种不同类型的值返回
}