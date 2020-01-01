#include <concurrent.h>
void ClearKeyChain(JsonKey* head){  //清空JsonKey缓冲表
    JsonKey *p;
    while(head != NULL){
        p = head;
        head = head->nextk;
        free(p);
    }
}

void ClearValueChain(JsonValue* head){  //清空JsonValue缓冲表
    JsonValue* p;
    while(head != NULL){
        p = head;
        head = head->nextv;
        free(p);
    }
}