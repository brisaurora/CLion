#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstdio>
#include <cstring>
#define PORT 6666
#define MAXSIZE 1024
using namespace std;
int main(int argc, char *argv[])
{
    int sockfd, newsockfd;
    struct sockaddr_in server_addr;//定义服务端套接口数据结构
    struct sockaddr_in client_addr;
    char buf[MAXSIZE];//发送数据缓冲区
    sockfd = socket(AF_INET, SOCK_STREAM, 0);//定义客户端套接口数据结构
    printf("sockfd is %d\n", sockfd);
    bzero(&server_addr, sizeof(struct sockaddr_in));//清空表示地址的结构体变量
    server_addr.sin_family = AF_INET;//设置addr的成员变量信息
    server_addr.sin_port = htons(PORT);//设置服务器端口
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);//设置ip为本机IP
    bind(sockfd, (struct sockaddr*)(&server_addr), sizeof(struct sockaddr));
    puts("bind success\n");
    listen(sockfd, 10) ;//启动监听
    puts("listen success\n");
    int sin_size = sizeof(struct sockaddr_in);
    newsockfd = accept(sockfd, (struct sockaddr *)(&client_addr), reinterpret_cast<socklen_t *>(&sin_size));//接收连接请求
    printf("Accept clent ip is %s\n", inet_ntoa(client_addr.sin_addr));
    printf("Connect successful please input message\n");
    memset(buf,0,sizeof (buf));
    while (1)
    {
        int len = recv(newsockfd, buf, sizeof(buf), 0);//接收信息
        if (strcmp(buf, "exit") == 0)
            break;
        if(len>0) {
            puts("data accept:");
            puts(buf);//显示接收
            send(newsockfd, buf, len, 0);//发送信息
            memset(buf, 0, sizeof(buf));//清空缓存区
        }
    }
    close(newsockfd);
    close(sockfd);
    puts("exit success");
    return  0;
}