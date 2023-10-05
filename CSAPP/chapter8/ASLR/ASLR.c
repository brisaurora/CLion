#include <stdio.h>
#include "string.h"
#include "malloc.h"

int main() {

    int i;
    int n;
    int *p =(int *)malloc(sizeof(int));
    long p_offset=0x555555756260;
    long stack_offset=0x7fffffffdff8;
    printf("%p %x\n",p,p-0x555555756260);
    printf("%p\n %x",&i,(&i)-0x7fffffffdff8);
    *p=1;
    free(p);
    //scanf("%d",&n);
    if(n<=0)
        printf("Input error!\n");
    else
    {
        for(i=0;i<7;i++)
        {
            n=(n+1)*2;
        }
        printf("%d\n",n);
    }


    return 0;
}

