#include <concurrent.h>


char* Analysis(char* receiveBuff){    //分析客户端传来的数据
    receiveBuff = Base64Decode(receiveBuff);

    char* errStr = (char*)malloc(BIG_SIZE); //函数异常错误信息
    char* stu = (char*)malloc(BIG_SIZE);  //业务逻辑函数返回值
    char* returnStr = (char*)malloc(BIG_SIZE);  //函数正常执行信息
    if (stu == NULL){
        return (char*)"ERROR!";
    }

    if (errStr == NULL) {
        return (char*)"ERROR!";
    }

    if (returnStr == NULL) {
        return (char*)"ERROR!";
    }
    memset(errStr,'\0',sizeof(errStr));
    memset(stu,'\0',sizeof(stu));
    memset(returnStr,'\0',sizeof(returnStr));
    char* idx;
    
    idx = GetIndex(receiveBuff);
    printf("%s\n",idx);
    //根据特定请求类型，将任务分发给各个函数，完成相应的业务逻辑，并返回将要回返给客户端的一个字符串
    if (strcmp(idx,"CheckUsrPwd") == 0){   //验证用户名密码
        stu = CheckUsrPwd(conn,receiveBuff);
        if (strcmp(stu,"usr_or_pwd_wrong") == 0){
            strcpy(returnStr,"no");
        }
        else if (strcmp(GetIndex(stu),"yes") == 0){
            strcpy(returnStr,"yes");
        }
        else {
            strcpy(returnStr,"error");
        }
    }
    else if (strcmp(idx,"Search") == 0){  //查询信息
        stu = Search(conn,receiveBuff);
        if (strcmp(stu,"username_not_found") == 0){
            strcpy(returnStr,"username_not_found");
        }
        else if (strcmp(GetIndex(stu),"yes") == 0){
            return stu;  //查询出来的数据
        }
        else {
            strcpy(returnStr,"error");
        }
    }
    else if (strcmp(idx,"Resize") == 0){  //修改信息
        stu = Resize(conn,receiveBuff);
        if (strcmp(stu,"username_is_not_existed") == 0){
            strcpy(returnStr,"username_is_not_existed");
        }
        else if (strcmp(GetIndex(stu),"yes") == 0){
            strcpy(returnStr,"yes");
        }
        else {
            strcpy(errStr,"error");
            return errStr;
        }        
    }
    else if (strcmp(idx,"Delete") == 0){  //删除信息
        stu = Delete(conn,receiveBuff);
        if (strcmp(stu,"username_is_not_existed") == 0){
            strcpy(returnStr,"no");
        }
        else if (strcmp(GetIndex(stu),"yes") == 0){
            strcpy(returnStr,"yes");
        }
        else {
            strcpy(errStr,"error");
            return errStr;
        }
    }
    else if (strcmp(idx,"Add") == 0){  //添加信息
        stu = Add(conn,receiveBuff);
        printf("%s\n",stu);
        if (strcmp(stu,"username_is_registered") == 0){
            strcpy(returnStr,"username_is_registered");
        }
        else if (strcmp(GetIndex(stu),"yes") == 0){
            strcpy(returnStr,"yes");
        }
        else {
            strcpy(errStr,"error");
            return errStr;
        }
    }
    else {  //错误命令或内存分配失败
        perror("invalid command or failed in malloc().\n");
        strcpy(errStr,"command_invalid_or_failed_in_malloc()");
        return errStr;
    }
    returnStr = Base64Encode(returnStr);
    return returnStr;
}
 

