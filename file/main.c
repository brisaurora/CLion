#include<stdio.h>
#include<linux/kernel.h>
#include<sys/syscall.h>
#include<linux/unistd.h>
#include "string.h"
int main()
{
    char read_path[4096];
    char write_path[4096];
    printf("read path:");
    scanf("%s",read_path);
    printf("\nwrite path:");
    scanf("%s",write_path);
    int read_len,write_len;
    read_len= strlen(read_path);
    write_len= strlen(write_path);
    long a=syscall(336,read_path,read_len,write_path,write_len);
    printf("\n%ld\n",a);
    return 0;

}