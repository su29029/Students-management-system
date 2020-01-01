#include <concurrent.h>
char* Delete(MYSQL connect,char* receiveBuff){  //删除数据
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
    if (mysql_real_connect(&connect,"0.0.0.0","su","tF#262420228","db_student",0,NULL,0)!=NULL){
        char* query = (char*)malloc(BIG_SIZE);

        i = 0;
        memset(returnString,'\0',sizeof(returnString));
        memset(query,'\0',sizeof(query));
        printf("Connection success!\n");
        mysql_query(&connect,"set names 'utf8'");
        mysql_query(&connect,"set character_set_server=utf8");
        mysql_set_character_set(&connect,"utf8");
        for (;(hk != NULL)||(hv != NULL);hk = hk->nextk,hv = hv->nextv){
            printf("%s:%s\n",hk->key,hv->value);
            if (strcmp(hk->key,"username") == 0){
                strcpy(stu->username,hv->value);
                strcat(query,"SELECT * FROM student WHERE username=");
                strcat(query,stu->username);
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
                    if (rowNum == 0){//未找到待删除信息
                        strcat(returnString,"username_is_not_existed");
                        ClearKeyChain(hk);
                        ClearValueChain(hv);  
                        mysql_close(&connect);
                        return returnString;
                    }  //rowNum只在这里使用
                    else {
                        strcat(returnString,"result=yes");
                        memset(query,'\0',sizeof(query));
                        strcat(query,"delete from student where username='");
                        strcat(query,stu->username);
                     
                        
                    }
                }
            }
            else if (strcmp(hk->key,"name") == 0){
                strcpy(stu->name,hv->value);
                strcat(query,"' and ");
                strcat(query,"name='");
                strcat(query,stu->name);
                strcat(query,"'");
            }
            else;
        }
        printf("%s\n",query);
        res = mysql_query(&connect,query); 
        if (res){
            printf("error in delete.\n");
            memset(returnString,'\0',sizeof(returnString));
            strcpy(returnString,"error_in_delete");
            ClearKeyChain(hk);
            ClearValueChain(hv);  
            mysql_close(&connect);
            return returnString;
        }
        free(query);
        printf("%s\n",returnString);
    }
    ClearKeyChain(hk);
    ClearValueChain(hv);  
    mysql_close(&connect);
    return returnString;
}