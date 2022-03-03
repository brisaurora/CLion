#include <stdio.h>
#include "string.h"
typedef struct num
{
    char a;
    int t;
    long long int b;
    int k;


}num;
typedef union test
{
    int k[5];
    double c[2];
}test;
int main() {
    //测试结构体大小
    char str[40];
    struct num d;
    d.a=127;
    d.b=1;
    //d.k=-1;
    d.t=-1;
    memcpy(str,&d, sizeof(d));
    printf("%d %d\n", sizeof(d), sizeof(test));

    //测试指针间强制转化
    int xx;
    xx=-1;
    memset(str,0, sizeof(str));
    memcpy(str,&xx, 8);
    long long int *p=(long long *)&xx;
    memset(str,0, sizeof(str));
    memcpy(str,p, 8);
    printf("%lld",*p);
    //类型转化测试
    char test=-1;
    unsigned test2=(unsigned int )test;
    memset(str,0, sizeof(str));
    memcpy(str,&test2, 4);
    printf("%lu",(unsigned  int)test);
    return 0;
}
