#include <stdio.h>
#include <signal.h>
#include <setjmp.h>
//#include "utils.h"
#include <unistd.h>
#include<stdlib.h>
#define USE_SIG_LONG_JMP

int main(void)
{
    printf("Now call the abort.\n");
  

        abort();
   
        printf("abort failed.\n");
    return 0;
}
