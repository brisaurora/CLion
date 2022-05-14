#include <stdio.h>
#include "string.h"
#include "malloc.h"
void copy(char str1[],char str[])
{

    strcpy(str1,str);
    puts(str1);

}
int main() {
    char *p;
    for(int i=0;i<10;i++)
    {
        p=malloc(32);
        memset(p,i,32);
        //*p--;
        printf("%p %d\n",p,*p);
        printf("%p %s\n",p,((int)p%8)==0?"yes":"no");

    }

    *p=10;
    //不加括号导致地址先减少
    (*p)--;
    printf("%p %d\n",p,*p);
    printf("Hello, World!\n");


    return 0;
}
