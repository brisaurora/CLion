#include <iostream>
#include "sys/unistd.h"
#include "arpa/inet.h"
#include "cstring"
using namespace std;
typedef unsigned int u32_t;
struct ip_addr{
    u32_t addr;
};
#define PP_HTONL(x) ((((x) & (u32_t)0x000000ffUL) << 24) | \
                     (((x) & (u32_t)0x0000ff00UL) <<  8) | \
                     (((x) & (u32_t)0x00ff0000UL) >>  8) | \
                     (((x) & (u32_t)0xff000000UL) >> 24))
#define LWIP_MAKEU32(a,b,c,d) (((u32_t)((a) & 0xff) << 24) | \
                               ((u32_t)((b) & 0xff) << 16) | \
                               ((u32_t)((c) & 0xff) << 8)  | \
                                (u32_t)((d) & 0xff))
#define IP4_ADDR(ipaddr, a,b,c,d)  (ipaddr)->addr = PP_HTONL(LWIP_MAKEU32(a,b,c,d))
int main() {

    struct ip_addr ipaddr;
    IP4_ADDR(&ipaddr, 192,168,172,130);
    int fd=socket(AF_INET,SOCK_STREAM,0);//申请socket
    struct sockaddr_in cli_addr;
    cli_addr.sin_family = AF_INET;
    cli_addr.sin_port = htons(6666);//服务器端口
    cli_addr.sin_addr.s_addr=ipaddr.addr;//inet_addr("192.168.172.130");//服务器地址
    connect(fd,(struct sockaddr*)&cli_addr,sizeof(cli_addr));//连接服务器

    char buf[30];//缓冲区

    while(true){
        cin>>buf;//输入发送消息
       // printf("%s\n",buf);
        write(fd,buf,strlen(buf));//发送消息
        printf("send data:%s\n",buf);
        memset(buf, 0, sizeof(buf));//清空缓冲区
        int len = recv(fd, buf, sizeof(buf), 0);//接收消息
        buf[len] = '\0';
        printf("receive data:%s\n",buf);
        if(strcmp(buf,"close")==0)//判断是否关闭连接
            break;
    }

    printf("close tcp\n");
    close(fd);
    return 0;
}
