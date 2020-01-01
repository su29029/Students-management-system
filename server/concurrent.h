#ifndef CON_CURRENT_H
#define CON_CURRENT_H

#include <netinet/in.h>
#include <arpa/inet.h>
#include <mysql/mysql.h>
#include <mysql/mysqld_error.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <fcntl.h>  
#include <errno.h>
#include <pthread.h>
#include <signal.h>

#define BACKLOG	5		//允许的连接队列长度
#define PORT	7546	//连接端口
#define RECVBUFF 1024   //接收缓冲区长度
#define SENDBUFF 1024   //发送缓冲区长度
#define NORMAL_SIZE 64
#define BIG_SIZE 256
#define SMALL_SIZE 8
#endif

typedef struct JsonKey {
    char key[NORMAL_SIZE];    //键
    struct JsonKey* nextk;
}JsonKey;

typedef struct JsonValue {
    char value[NORMAL_SIZE];  //值
    struct JsonValue* nextv;
}JsonValue;

typedef struct Json{  //键值对
    JsonKey* key;
    JsonValue* value;
}Json;

typedef struct Student{  //学生信息
    char username[NORMAL_SIZE/2];  //学号
    char password[NORMAL_SIZE/2];  //密码
    char name[NORMAL_SIZE/2];  //姓名
    char sex[SMALL_SIZE/2];  //性别
    char major[NORMAL_SIZE];  //专业
    char grade[SMALL_SIZE/2];   //年级
    int age;  //年龄
    int midTermScore;  //期中成绩
    int finalTermScore;  //期末成绩
}Student;


MYSQL conn;    //MYSQL连接句柄

static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

/*
    函数名：Analysis
    参数：ReceiveBuff 客户端发来的数据包。
    功能：判断客户端的请求业务类别，并完成业务分发，分发给相关的函数进行处理。
    返回值：char* 类型，需要回返给客户端的数据。
*/
char* Analysis(char*);


/*
    函数名：ParseReceive
    参数：ReceiveBuff 客户端发来的数据包
    功能：将客户端发来的数据包（查询字符串格式）进行解析，解析成类似Json的键值对格式，并将键和值分别存入对应的缓冲链表
    返回值：Json* 类型，解析完成后的 两个缓冲链表的头指针组成的 Json型数据
*/
Json* ParseReceive(char* );


/*
    函数名：GetIndex
    参数：ReceiveBuff 客户端发来的数据包
    功能：获取客户端的请求业务类别
    返回值：char* 类型，获取到的客户端请求业务类别
*/
char* GetIndex(char*);


/*
    函数名：CheckUsrPwd
    参数：conn MySQL连接句柄，ReceiveBuff 客户端发来的数据包
    功能：检查登录用户名和密码是否正确
    返回值：char* 类型，判断结果或函数执行结果
*/
char* CheckUsrPwd(MYSQL,char*);


/*
    函数名：Search
    参数：conn MySQL连接句柄，ReceiveBuff 客户端发来的数据包
    功能：执行搜索数据操作
    返回值：char* 类型，判断结果或函数执行结果
*/
char* Search(MYSQL,char*);


/*
    函数名：Delete
    参数：conn MySQL连接句柄，ReceiveBuff 客户端发来的数据包
    功能：执行删除某一数据操作
    返回值：char* 类型，判断结果或函数执行结果
*/
char* Delete(MYSQL,char*);


/*
    函数名：Resize
    参数：conn MySQL连接句柄，ReceiveBuff 客户端发来的数据包
    功能：执行修改数据操作
    返回值：char* 类型，判断结果或函数执行结果
*/
char* Resize(MYSQL,char*);


/*
    函数名：Add
    参数：conn MySQL连接句柄，ReceiveBuff 客户端发来的数据包
    功能：执行添加数据操作
    返回值：char* 类型，判断结果或函数执行结果
*/
char* Add(MYSQL,char*);


/*
    函数名：ClearKeyChain
    参数：head JsonKey类型头指针
    功能：清空JsonKey缓冲链表
    返回值：空
*/
void ClearKeyChain(JsonKey*);


/*
    函数名：ClearValueChain
    参数：head JsonValue类型头指针
    功能：清空JsonValue缓冲链表
    返回值：空
*/
void ClearValueChain(JsonValue*);


/*
    函数名：Base64Encode
    参数：str 欲base64编码的字符串
    功能：将字符串进行base64编码
    返回值：编码后的字符串
*/
char* Base64Encode(char*);


/*
    函数名：Base64Decode
    参数：code 欲base64解码的字符串 
    功能：将字符串进行base64解码
    返回值：解码后的字符串
*/
char* Base64Decode(char*);
