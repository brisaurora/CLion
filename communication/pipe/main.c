#include <stdio.h>
#include "signal.h"
#include "sys/wait.h"
#include "sys/types.h"
#include <unistd.h>
#include "string.h"
#include "semaphore.h"
#include<fcntl.h>
#include "stdlib.h"
#define rep(i,a,b) for(i=(a);i<(b);i++)

int main() {
    int mypipe[2];
    int pid;
    int i;
    char OutPipe[90000],InPipe[100];
    sem_t *pipe_sem_read,*pipe_sem_write;//有名信号量
    sem_unlink("pipe_sem_read");//取消信号量连接防止因为错误退出存在的信号量
    sem_unlink("pipe_sem_write");
    pipe_sem_read= sem_open("pipe_sem_read",O_CREAT,0666,0);
    pipe_sem_write= sem_open("pipe_sem_write",O_CREAT,0666,1);
    pipe(mypipe);//创建管道
    fcntl(mypipe[1],F_SETFL,O_NONBLOCK);

    //检验信号量是否正常
    if(pipe_sem_write==SEM_FAILED||pipe_sem_read==SEM_FAILED)
        printf("sem_open_error\n");
    else
        printf("sem_open success!\n");

    //创建进程
    printf("father pid is %d\n",getppid());
    pid=fork();

    //发送数据
    if(pid==0)
    {
        while (1) {
            int ret;
            sprintf(InPipe,"A");
            ret=write(mypipe[1],InPipe,strlen(InPipe)+1);
            if(ret==-1)
                break;

        }
        sem_post(pipe_sem_read);
    }
    else
    {
        sem_wait(pipe_sem_read);
        int read_num;
        memset(OutPipe,0,sizeof(OutPipe));
        read_num=read(mypipe[0],OutPipe,sizeof(OutPipe));
        printf("output %d\n",read_num);
    }
    return 0;
}