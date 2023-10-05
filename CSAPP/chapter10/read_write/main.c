
#include <stdio.h>
#include "fcntl.h"
int main(void) {
    FILE *fd;
    fd= fopen("read.txt","w+");
    char buf[20]="abcdefg";
    memset(buf,'c',20);
    strcpy(buf,"abcdefg");
    *(buf+7)='k';
    buf[19]='\0';
    fwrite(buf,20,1,fd);
    fclose(fd);
    fd= fopen("read.txt","r");
    char read1[50];
    unsigned long long count=fread(read1,1,20,fd);
    printf("%llu %s\n",count,read1);
    count=fread(read1,1,20,fd);
    printf("%llu %s\n",count,read1);
    return 0;
}
