#include <stdio.h>
#include "string.h"
typedef struct num
{
    char a;
    long  int b;
    short k;
}num;
typedef union test
{
    int k[3];
    double c;
}test;
int main() {
    char str[12];
    struct num d;
    test k;
    d.a=127;
    d.k=-1;
    //memcpy(str,&d, sizeof(d));
    printf("%lu %lu\n", sizeof(d), sizeof(k));

    return 0;
}

