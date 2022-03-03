#include <stdio.h>
void test_address(void *x);
void test_address_b(void **b);
int main() {
    //x,&x
    char d;
    char *x;
    d='2';
    x=&d;
    printf("%p %p begin\n",x,&x);
    test_address(x);
    printf("%p %d",x,*x);
    test_address_b((void **) &x);
    printf("kkk%d",x==NULL);
    return 0;
}
int y=0;
void test_address_b(void **b)
{
    *b=0;
}
void test_address(void *x)
{
    //此函数证明，函数参数本身也是一个指针类型，是一个指向对象的指针，对此指针操作，并不会影响主函数中指针的数值，需要特别注意
    char *t;
    t=(char *)x;
    printf("%p %p %c this is deep:%d\n",x,&x,*t,y);
    y++;
    if(y<5)
        test_address(&x);
    y--;
    printf("%p %p %c this is deep:%d\n",x,&x,*t,y);
    x=0;
}