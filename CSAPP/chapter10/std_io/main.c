#include <stdio.h>
#include "malloc.h"
#include "string.h"
int main()
{
    FILE* f = fopen("io.txt", "r+"); // open for read/write
    if (f == NULL)
    {
        perror("fopen");
        return 0;
    }
    char c[12];
    //*************************************************
    //测试读操作对写操作位置的影响
    fread(c, 1, 11, f);//读后写，无法写入
    printf("read msg is:%s\n",c);
    char* first = "first_1_first_2";
    char* sencond = "second_1_second_2";
    int len = ftell(f);
    printf("test1:offset is:%d before write\n",len);
    fseek(f,0,SEEK_CUR);
    unsigned long long err=fwrite(first, 1, 2, f); // make sure the stream has 4 bytes
    len= ftell(f);
    printf("test1:offset is:%d after write\n",len);
    printf("return is:%llu\n",err);
   if(ferror(f))
       printf("f error\n");
    if(feof(f))
        printf("f eof\n");
    fflush(f);
    //*************************************************//
    //测试写操作对读操作位置的影响
    memset(c,0,sizeof(c));
   // fseek(f,7,SEEK_SET);//刷新缓冲区，并重新定位位置
    fread(c, 1, 5, f);
    printf("%s\n",c);
    len = ftell(f);
    printf("offset is:%d\n",len);
    rewind(f); // reset position indicator
    len = ftell(f);
    printf("offset is:%d\n",len);
    fwrite(sencond, 1, 5, f); // write one byte at the beginning
  //  fflush(f);//不加这行，下一次读取数据时，会导致读取位置错误，并导致错误读取的数据被写入文件
    memset(c,0, sizeof(c));
    fread(c, 1, 7, f); // read after write
    len= ftell(f);
    printf("%s len:%d\n", c,len); // what's in c2?
    //fflush(f);//读后写加这行无效，不会解决读写异常的问题
    //fseek(f,0,SEEK_CUR);//不加这行导致下面这行写入失败
    fwrite(sencond, 1, 1, f); // write after read
    fclose(f); // what's in the file now?

    return 0;
}