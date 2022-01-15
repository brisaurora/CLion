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
    char OutPipe[90000],InPipe[100];
    pipe(mypipe);//创建管道
    fcntl(mypipe[1],F_SETFL,O_NONBLOCK);
    while (1) {
        int ret;
        sprintf(InPipe,"c");
        ret=write(mypipe[1],InPipe,strlen(InPipe)+1);
        if(ret==-1)
            break;
    }
    int read_num;
    memset(OutPipe,0,sizeof(OutPipe));
    read_num=read(mypipe[0],OutPipe,sizeof(OutPipe));
    printf("output %d\n",read_num);
    return 0;
}