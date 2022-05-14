#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include <string.h>
//#include<unistd.h>
//#include<sys/types.h>
#define GitHub_upload 
#ifdef GitHub_upload
    #define n 100
#else
    #define n 1024*1024*1024*1
#endif
char str1[n]="12";
//char str2[n];
//char str3[n];
//char str4[n];
//本程序用来测试Linux和WIn10下，SWAP区的变化
int main()
{
  //  memset(str1,1,sizeof(str1));
//    memset(str2,1,sizeof(str2));
//    memset(str3,1,sizeof(str3));
//    memset(str4,1,sizeof(str4));
    str1[n-1]='\0';//str2[n-1]='\0';str3[n-1]='\0';str4[n-1]='\0';
    //printf("%s",str);
    while(1){

    }
    return 0;
}