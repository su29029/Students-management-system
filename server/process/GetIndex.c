#include <concurrent.h>
char* GetIndex(char* receiveBuff) {  //获取请求类型（增、删、改、查） 不是get post请求
    char* index;
    int number = 0;
    int i = 0;

    index = (char*)malloc(NORMAL_SIZE/2);
    if (index == NULL){
        return (char*)"ERROR!";
    }
    memset(index,'\0',NORMAL_SIZE/2);

    for (i = 0; i <= strlen(receiveBuff);i++){  //获取查询字符串个数，以备后用
        if (receiveBuff[i] == '='){
            number++;
            continue;
        }
    }
    if (number == 0) return (char*)"not_a_query";

    int start = 0;
    int end = 0;
    for (start = 0; start<strlen(receiveBuff);start++){  //通过读取查询字符串的第一个部分，获取请求类型
        if (receiveBuff[start] == '='){
            for (end = start;end<strlen(receiveBuff);end++){
                if (receiveBuff[end] == '&') {
                    break;
                }
            }
        break;
        }         
    }
    strncpy(index,&(receiveBuff[start+1]),end-start-1);  //保存请求类型并返回
    //printf("%s\n",index);
    return index;
}