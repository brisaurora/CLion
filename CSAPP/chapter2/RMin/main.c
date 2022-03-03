#include <stdio.h>
#include "limits.h"
#include "string.h"
#include "math.h"
#define NUM -2147483647
#define NUM1 -2147483648
int main() {
    int x=NUM;
    printf("%d",2147483648U);
    printf("%llu %llu,%llu\n", sizeof(NUM), sizeof(NUM1) ,sizeof(INT_MIN));

    unsigned int k=1;
    if(k>NUM)
        printf("unsigned num don't change signed num to unsigned num\n");
    else
        printf("unsigned num changes signed num to unsigned num\n");

    //移位
    short i=-2;
    int t=(int)i>>31;
    printf("%d\n",t);

    //测试无符号数字
    unsigned short y=0u,lll=1;
    signed short j;
    char str[3];
    for(j=0;j<=(y-2);j++) {
        //y=(y-1);
        //memcpy(str,&y,2);
        //j=y-1;
        printf("%d ", j);
    }

    //测试浮点数极限大小
    double a,b,c,a1,a2;
    c=0;
    a=1;
    b=-1;
    a1=1.0/1e308;
    a2=-INFINITY;
    printf("%lf %lf %lf %lf",a1,a2,a1+a2,1.0/a1);
    return 0;
}
