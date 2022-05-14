#include <stdio.h>
#include <setjmp.h>
jmp_buf buf;
int erron2=1;
int erron1=1;
void foo1()
{
    if(erron2)
        longjmp(buf,2);
}

void foo()
{
    if(erron1)
        longjmp(buf,-2);
    foo1();
}
int main() {

    switch (setjmp(buf)) {
        case 0:
            printf("case 0\n");
            foo();break;
        case 1:
            printf("error 1\n");break;
        case 2:
            printf("error 2\n");break;
        case -2:
            printf("error -2\n");break;
        default:
            printf("unknow faulr\n");

    }

    return 0;
}
