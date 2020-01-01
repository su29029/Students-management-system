#include <concurrent.h>
char* Add(MYSQL connect,char* receiveBuff){  //添加数据
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
        //printf("check second\n");
        for (;(hk != NULL)||(hv != NULL);hk = hk->nextk,hv = hv->nextv){
            //printf("check second in a loop.\n");
            printf("%s:%s\n",hk->key,hv->value);
            if (strcmp(hk->key,"username") == 0){
                strcpy(stu->username,hv->value);
                strcat(query,"SELECT * FROM student WHERE username=");
                strcat(query,stu->username);
                printf("%s\n",query);
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
                    if (rowNum != 0){//找到了数据库里原来就有这条信息，说明已被注册，故返回已被注册的错误信息
                        strcat(returnString,"username_is_registered");
                        ClearKeyChain(hk);
                        ClearValueChain(hv);  
                        mysql_close(&connect);
                        return returnString;
                    }  //rowNum只在这里使用
                    else {
                        strcat(returnString,"result=yes");
                        memset(query,'\0',sizeof(query));
                        strcat(query,"insert into student values ('");
                        strcat(query,stu->username);
                        strcat(query,"','");
                        //printf("%s\n",query);
                    }
                }
            }
            else if (strcmp(hk->key,"password") == 0){
                strcpy(stu->password,hv->value);
                strcat(query,stu->password);
                strcat(query,"','");
            }
            else if (strcmp(hk->key,"name") == 0){
                strcpy(stu->name,hv->value);
                //printf("%s\n",stu->name);
                strcat(query,stu->name);
                strcat(query,"','");
            }
            else if (strcmp(hk->key,"sex") == 0){
                strcpy(stu->sex,hv->value);
                strcat(query,stu->sex);
                strcat(query,"','");
            }
            else if (strcmp(hk->key,"major") == 0){
                strcpy(stu->major,hv->value);
                strcat(query,stu->major);
                strcat(query,"','");
            }
            else if (strcmp(hk->key,"grade") == 0){
                strcpy(stu->grade,hv->value);
                strcat(query,stu->grade);
                strcat(query,"','");
            }
            else if (strcmp(hk->key,"age") == 0){
                char* age = (char*)malloc(SMALL_SIZE/2);
                stu->age = atoi(hv->value);
                sprintf(age,"%d",stu->age);
                strcat(query,age);
                free(age);
            }
            else;
        }
        //query        
        strcat(query,"','0','0')");
        printf("query:%s\n",query);
        res = mysql_query(&connect,query);
        if (res){
            printf("error in add.\n");
            memset(returnString,'\0',sizeof(returnString));
            strcpy(returnString,"error_in_add");
            ClearKeyChain(hk);
            ClearValueChain(hv);  
            mysql_close(&connect);
            return returnString;
        }
        memset(query,'\0',sizeof(query));
        strcat(query,"SELECT * FROM student WHERE username=");
        strcat(query,stu->username);
        printf("%s\n",query);
        res = mysql_query(&connect,query);
        if (res){
            printf("error in check.\n");
            memset(returnString,'\0',sizeof(returnString));
            strcpy(returnString,"error_in_check");
            ClearKeyChain(hk);
            ClearValueChain(hv);  
            mysql_close(&connect);
            return returnString;
        }
        //printf("finish check.\n");
        //check
        result = mysql_store_result(&connect);
        if (result){
            rowNum = mysql_num_rows(result);
            colNum = mysql_num_fields(result);
            char* fields[colNum],*cols[colNum];
            for (i = 0;i < colNum;i++){
                cols[i] = (char*)malloc(BIG_SIZE*sizeof(char));
                if (cols[i] == NULL){
                    exit(-1);
                }
                memset(cols[i],'\0',BIG_SIZE*sizeof(char));
                fields[i] = (char*)malloc(BIG_SIZE*sizeof(char));
                if (fields[i] == NULL){
                    exit(-1);
                }
                memset(fields[i],'\0',BIG_SIZE*sizeof(char));
            }
            i = 0;
            while (fd = mysql_fetch_field(result)){
                printf("%s\t",fd->name);
                strcat(fields[i],fd->name);
                i++;
            }
            printf("\n");
            while (sqlRow = mysql_fetch_row(result)){    
                for (i = 0;i < colNum;i++){
                    if (sqlRow[i] == NULL) 
                        printf("NULL\t");
                    printf("%s\t",sqlRow[i]);
                    strcat(cols[i],sqlRow[i]);
                }
                printf("\n");
            }
            for (i = 0;i < colNum;i++){  
                strcat(returnString,"&");  
                strcat(returnString,fields[i]);
                strcat(returnString,"=");
                strcat(returnString,cols[i]);
            }
            for (i = 0;i < colNum;i++){
                free(cols[i]);
                free(fields[i]);
            }
        }  
        free(query);  
        //strcpy(returnString,"212123");
        printf("return:%s\n",returnString);
    } 
    ClearKeyChain(hk);
    ClearValueChain(hv);  
    mysql_close(&connect);
    return returnString;
}