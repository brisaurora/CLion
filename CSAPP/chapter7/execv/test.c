#include<unistd.h>
#include<stdio.h>
#include<string.h>
int main(int argc,char **argv,char **envp)
{
     char *argvw[3];
     argvw[1]=NULL;
     printf("start new exe\n");
     int err=execve("./execve",argv,envp);
     int err1=execv("./prog2r",argvw);
     printf("%d inewe\n",err);
     return 0;
}
