#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include <string.h>
#include<unistd.h>
#include<sys/types.h>
#define n 1024*1024*1024*1
char str1[n]="123";
//char str2[n];
//char str3[n];
//char str4[n];
int main()
{
    fork();fork();fork();
    memset(str1,1,sizeof(str1));
//    memset(str2,1,sizeof(str2));
//    memset(str3,1,sizeof(str3));
//    memset(str4,1,sizeof(str4));
    str1[n-1]='\0';//str2[n-1]='\0';str3[n-1]='\0';str4[n-1]='\0';
    //printf("%s",str);
    while(1){

    }
    return 0;
}
