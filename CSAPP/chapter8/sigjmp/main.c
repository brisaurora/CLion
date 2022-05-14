#include <stdio.h>
#include <setjmp.h>
#include "signal.h"
sigjmp_buf buf;
void handle(int sig)
{
    siglongjmp(buf,2);
}

int main() {
    switch (sigsetjmp(buf,1)) {
        case 0:signal(SIGINT,handle);
            printf("sucess initial\n");
            while (1)
            {}break;
        case 2:
            printf("error 2\n");break;
        default:
            printf("unknow error\n");
    }
    return 0;
}
