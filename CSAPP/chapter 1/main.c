#include<stdio.h>

static int x;
int y=1;
char s[100]="12332";
char t[200];
int main()
{

//x=sum();
fun();
printf("%d\n",x);
printf("%d3\n",y);
printf("%d2\n",y);
return 0;
}
int fun()
{
    static x=0;
    return x;
}
int g()
{
    static x=1;
    return x;
}
