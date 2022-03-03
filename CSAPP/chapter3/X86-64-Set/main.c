#include "stdio.h"
void test(int x,int y,int a,int b,int c,int d,int e)
{

    int z;
    x++;
    y++;
    a++;
    b++;
    c++;
    d++;
    e++;
    z=a+b+c+d+e+x+y;
    z++;
}
void test1(int x,int y)
{
    x++;
    y++;
    int z=x+y;
    int k=y*2;
    int tc=x*y;
    int zz=k*tc+x;
    z++;
    int ty=k*tc+zz;
    ty=z+ty;
}

union test1{
    double c;
    int k[2];
}test2;
enum day
{
    MON=0x7fffffff-2,
    TUS,
    TES=10,
    TESS
};
int main()
{
    //传参测试
    int x,y,z;
    x=1;
    y=128;
    x<<=y;
    x++;
    z=x;
    z++;
    printf("%d %d %d %d",MON,TUS,TES,TESS);
    test(1,2,3,4,5,6,(char)7);
    int a[7],ii;
    test1(x,y);


    //SWITCH
    static  void *jt[7]={
            &&loc_A
    };
    loc_A:
            ii=2;
    switch (ii=3) {
        case 0:
            printf("yes");
    }

    //Union
    union test1 k;
    k.k[0]=0xffff332;
    k.k[1]=0xfffffffd;
    printf("%lf",k.c);

    //double to float
    double X64_double=1.8;
    float X64_float=1223.56;
    X64_float=(float )X64_double;
    X64_double=(double )X64_float;
    return 0;

}
