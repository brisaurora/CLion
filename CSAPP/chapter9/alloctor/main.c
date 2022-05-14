#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
int bssvar;    //声明一个味定义的变量，它会放在 bss segment 中
int main()
{
    char *p=NULL,*p1=NULL,*p2=NULL;
    int i=0,maxsize=64*1024;
    printf("pid:%d\n",getpid());
    printf ("end of bss section:%p\n", (void *)&bssvar + 4);
    p=(char *)malloc(maxsize);
    printf("gap between 。bss and heap:%ld\n",(void *)p-(void *)&bssvar - 4);
    printf("size to brk:%ld\n",(void *)sbrk(0)-(void *)p);

    while(1)
    {
        //if(i<100)
            *(p+i)='c';
        if(!i)
            printf("p:%p\n",p);
        i++;
        if(i<=100)
            break;

    }
   // getchar();
    //printf("brk:%p \n",sbrk(maxsize*2));
    //printf("brk:%p\n",sbrk(0));
    p1=(char *)malloc(maxsize);
    printf("gap between p1 and p:%ld\n",(void *)p1-(void *)p);
    printf("size to brk:%ld\n",(void *)sbrk(0)-(void *)p1);
    //printf("P1 and brk size:%ld \n",(void *)sbrk(0)-(void *)p1-maxsize);
    i=0;

    while(1)
    {
        if(p1==NULL)
        {
            printf("error break;\n");
            break;
        }
        else if(!i)
            printf("p1:%p\n",p1);
        *(p1+i%(maxsize))='c';
        i++;
        if(i>=maxsize)
            break;
    }
    printf("*************************\n");
    p2=(char *)malloc(18);
    printf("p2:%p\n",p2);
    printf("gap between p2 and p1:%ld\n",(void *)p2-(void *)p1);
    printf("size to brk:%ld\n",(void *)sbrk(0)-(void *)p2);
    printf("*************************\n");
    char *p3=(char *)malloc(2360);
    memset(p3,'c',2360);
    printf("p3:%p\n",p3);
    printf("gap between p3 and p2:%ld\n",(void *)p3-(void *)p2);
    printf("P3 size to brk:%ld\n",(void *)sbrk(0)-(void *)p3);
    printf("before brk:%p\n",sbrk(0));
    printf("*************************\n");
    //此处准确用完了135200B大小的堆,堆顶部保留剩下的16B不使用
    //free(p2);
    //free(p3);
    //再次调用malloc会分配新页,观察P4至brk的大小可知，获取页数量为33，页大小为4096B
    char *p4=(char *)malloc(232);
    memset(p4,'c',2);
    printf("size to brk:%ld\n",(void *)sbrk(0)-(void *)p4);
    printf("allocated P4 brk:%p\n",sbrk(0));
    //释放空间观察堆顶变化
    free(p4);
    printf("FREE P4 brk:%p\n",sbrk(0));
   // getchar();
    free(p1);
    free(p2);
    free(p3);
    free(p);
    p=(char *) malloc(1);
    printf("brk:%p\n",sbrk(0));
    //getchar();
    return 0;
}