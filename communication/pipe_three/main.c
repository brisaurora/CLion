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
    int pid[3];
    int i;
    char OutPipe[70000],InPipe[100];
    sem_t *pipe_sem_read,*pipe_sem_write;//有名信号量
    sem_unlink("pipe_sem_read");//取消信号量连接防止因为错误退出存在的信号量
    sem_unlink("pipe_sem_write");
    pipe_sem_read= sem_open("pipe_sem_read",O_CREAT,0666,0);
    pipe_sem_write= sem_open("pipe_sem_write",O_CREAT,0666,1);
    pipe(mypipe);//创建管道
    //fcntl(mypipe[0],F_SETFL,O_NONBLOCK);
    memset(pid,-1,sizeof(pid));

    //检验信号量是否正常
    if(pipe_sem_write==SEM_FAILED||pipe_sem_read==SEM_FAILED)
        printf("sem_open_error\n");
    else
        printf("sem_open success!\n");

    //创建进程
    printf("father pid is %d\n",getppid());
    rep(i,0,3) {
        pid[i]=fork();
        if(pid[i]==0)
            break;
        else
            printf("father have a child:%d\n",pid[i]);
    }
    //发送数据
    rep(i,0,3)
    {
        if(pid[i]==0)
        {

            while (1)
            {
                fflush(stdout);
                switch (i) {
                    case 0:sprintf(InPipe,"I am a children %d\n",i);break;
                    case 1:sprintf(InPipe,"This is children %d\n",i);break;
                    case 2:sprintf(InPipe,"the children of father is %d\n",i);break;
                }
                sem_wait(pipe_sem_write);
                rep(i,0,12)
                    write(mypipe[1],InPipe,strlen(InPipe)+1);
                sem_post(pipe_sem_write);
                printf("input %s", InPipe);
                sem_post(pipe_sem_read);
                sleep(i);
            }
        }

    }
    int status=0;
    rep(i,0,3)
        if(pid[i]==0)
            status=1;
    if(!status)
    {
        int read_num;
        while (1)
        {
            sem_wait(pipe_sem_read);
            memset(OutPipe,0,sizeof(OutPipe));
            read_num=read(mypipe[0],OutPipe,sizeof(OutPipe));
            printf("output %s",OutPipe);
            printf("output %d\n",read_num);
        }
    }
    return 0;
}