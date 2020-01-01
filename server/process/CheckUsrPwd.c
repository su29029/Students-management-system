#include <concurrent.h>

char* CheckUsrPwd(MYSQL connect,char* receiveBuff){  //检查用户名密码
    int res;
    Student* stu;

    MYSQL_RES* result;   //MYSQL_RES* 类型  mysql_store_result(MYSQL* )返回值
    int rowNum,colNum;
    int i = 0;
    MYSQL_FIELD* fd;   //MYSQL_FIELD* 类型 mysql_fetch_field(MYSQL_RES* )返回值
    MYSQL_ROW sqlRow; //字符串数组

    Json* json;
    JsonKey* hk;
    JsonValue* hv;
    char* returnString;
    json = (Json*)malloc(sizeof(Json));
    hk = (JsonKey*)malloc(sizeof(JsonKey));
    hv = (JsonValue*)malloc(sizeof(JsonValue));
    stu = (Student*)malloc(sizeof(Student));
    returnString = (char*)malloc(BIG_SIZE);

    if (json == NULL){
        return (char*)"ERROR!";
    }
    if (hk == NULL){
        return (char*)"ERROR!";
    }
    if (hv == NULL){
        return (char*)"ERROR!";
    }
    if (stu == NULL){
        return (char*)"ERROR!";
    }
    if (returnString == NULL){
        return (char*)"ERROR!";
    }
    json = ParseReceive(receiveBuff);  //此时ReceiveBuff中的所有数据已完成格式化并按顺序存入JSON_KEY和JSON_VALUE链表中  
    
    hk = json->key;  //headk已经赋给hk
    hv = json->value;  //headv已经赋给hv  
    mysql_init(&connect);

    for (;(hk != NULL)&&(hv != NULL);hk = hk->nextk,hv = hv->nextv){  //将缓冲表中的值取出存入临时结构体中
        if (strcmp(hk->key,"username") == 0){
            printf("%s\n",hv->value);
            //如果为了防止sql注入，这里应当对hv->value做一个过滤
            strcpy(stu->username,hv->value);
        }
        else if (strcmp(hk->key,"password") == 0){
            printf("%s\n",hv->value);
            strcpy(stu->password,hv->value);
        }
        else;
    }

    if (mysql_real_connect(&connect,"0.0.0.0","su","tF#262420228","db_student",0,NULL,0)!=NULL){
        char* query = (char*)malloc(BIG_SIZE);
        i = 0;
        memset(returnString,'\0',sizeof(returnString));
        memset(query,'\0',sizeof(query));
        printf("Connection success!\n");
        mysql_query(&connect,"set character_set_server=utf8");
        mysql_query(&connect,"set names 'utf8'");
        mysql_set_character_set(&connect,"utf8");     
        strcat(query,"SELECT username,password FROM student WHERE username='");
        strcat(query,stu->username);
        strcat(query,"' and password='");
        strcat(query,stu->password);
        strcat(query,"'");
        res = mysql_query(&connect,query); 
        if (res){
            printf("error in select.\n");
            strcpy(returnString,"error_in_select");
            ClearKeyChain(hk);
            ClearValueChain(hv);  
            mysql_close(&connect);
            return returnString;
        }
        result = mysql_store_result(&connect);
        if (result){
            rowNum = mysql_num_rows(result);
            colNum = mysql_num_fields(result);
            if (rowNum == 0){
                strcat(returnString,"usr_or_pwd_wrong");
                ClearKeyChain(hk);
                ClearValueChain(hv);  
                mysql_close(&connect);
                return returnString;
            }
            else {
                strcat(returnString,"result=yes");
            }
        } 
        free(query);
        printf("%s\n",returnString);

    }
    ClearKeyChain(hk);
    ClearValueChain(hv);  
    mysql_close(&connect);
    return returnString;
}