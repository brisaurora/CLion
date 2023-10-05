#include<unistd.h>
#include<stdio.h>
#include<string.h>
int main(int argc,char **argv,char **envp)
{
     int i=0;
    printf("start %s\n",argv[i]);
	while(argv[i]!=NULL)
	{
	    printf("argv[%d]=%s\n",i++,argv[i]);
	}
	i=0;
     while(envp[i]!=NULL)
	{
	    printf("envp[%d]=%s\n",i++,envp[i]);
	}
     return 0;
}
