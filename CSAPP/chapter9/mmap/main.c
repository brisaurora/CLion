#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <malloc.h>
#include "stdio.h"
#include "string.h"
int main(){
    int fd;
    void *start;
    struct stat sb;
    char *p=NULL;
    p=(char *)calloc(24,sizeof(char));
    printf("%p %p\n", p,&p);
    int a[2][4];
    memset(p,2,24);
    p=(char *)realloc(p,25);
    memset(p,4,23);
    printf("%p\n", p);
    p=(char *)realloc(p,40);
    memset(p,5,40);
    printf("%p\n", p);
    fd = open("/etc/passwd", O_RDONLY); /*打开/etc/passwd */
    fstat(fd, &sb); /* 取得文件大小 */
    start = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    printf("start:%p\n sb:%p\n",start,&sb);
    if(start == MAP_FAILED) /* 判断是否映射成功 */
        return 1;
    //printf("%s", start);
    munmap(start, sb.st_size); /* 解除映射 */
    close(fd);
    return 0;
}