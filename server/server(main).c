
#include "concurrent.h"

// 并发服务器工作流程：
// 1.完成套接字初始化
// 2.阻塞等待客户端请求
// 3.当接收到客户端请求后，fork一个子进程完成客户端请求处理


int main(int argc,char** argv){

    int client;   //对端(客户端)套接字文件描述符
    int sfd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);  //创建套接字  ipv4协议簇  字节流套接字  使用TCP协议   (若第三个参数置零，则默认TCP/SCTP协议)
    if (sfd == -1){
        perror("create socket failed.");
        return -1;
    }
    
    struct sockaddr_in saddr;  //服务器端套接字地址结构
    struct sockaddr_in peer_saddr;  // 对端(客户端)套接字地址结构
    socklen_t peer_len = sizeof(struct sockaddr);   //由peer_saddr指定的套接字地址结构长度
    memset(&saddr,0,sizeof(saddr));  //这里也可使用bzero()函数  bzero(&saddr,sizeof(saddr))
    saddr.sin_family = AF_INET;  //指定ipv4协议簇
    saddr.sin_port = htons(PORT);  //端口   由主机字节序转化为网络字节序
    saddr.sin_addr.s_addr = htonl(INADDR_ANY);  //允许的ip地址 INADDR_ANY 即任意地址
    if(bind(sfd,(struct sockaddr*)&saddr,sizeof(struct sockaddr)) == -1){   //bind(). 绑定套接字 sfd 文件描述符 和 saddr 套接字地址结构
        perror("bind socket error!");
        return -1;
    }
    
    if(listen(sfd,BACKLOG) == -1){  //listen(). 启动监听  sfd主动套接字转化为被动监听套接字
        perror("listen error!");
        return -1;
    }
    
    while(1){  //无限循环接收客户端请求   TCP短连接 
        client = accept(sfd,(struct sockaddr*)&peer_saddr,&peer_len);   //收到客户端请求，接受请求  否则本步阻塞监听
        if (client == -1){
            perror("error in accept.");
            return -1;
        } 
        else {
            printf("accept client:%s:%d\n",inet_ntoa(peer_saddr.sin_addr),peer_len);
        }
        
        pid_t pid = fork();   //创建子进程
        if (pid < 0){
            perror("fork error."); 
            return -1;
        }
        else if (pid == 0) {
            close(sfd);  //关闭监听套接字

            char* receiveBuffer = (char*) malloc(RECVBUFF);   //接收缓冲区
            char* sendBuffer = (char*) malloc(SENDBUFF);      //发送缓冲区
            memset(receiveBuffer,'\0',sizeof(receiveBuffer));
            memset(sendBuffer,'\0',sizeof(sendBuffer));

            recv(client,receiveBuffer,RECVBUFF,0);  //若客户端发送了数据，接收客户端发来的数据 否则本步阻塞接收数据
            if((strcmp(receiveBuffer,"")) == 0){
                continue;
            }
            printf("recv:%s\n",receiveBuffer);

            strcpy(sendBuffer,Analysis(receiveBuffer));  //分析数据

            if (strcmp(sendBuffer,"") != 0){
                send(client,sendBuffer,SENDBUFF,0);  //向客户端回返数据
                printf("send:%s\n",sendBuffer);           
            }
            close(client);  //子进程关闭已连接套接字
            exit(0);
        }
        else {
            close(client);  //父进程关闭已连接套接字
        }
    }

    close(sfd);  //关闭套接字
    return 0;

}