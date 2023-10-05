#include <stdio.h>
#include "pthread.h"

char **ptr;
void fu() {
    static int d = 1;
    if (d != 1)
        printf("%d", d);

}

void fun1() {
    static int d = 3;
    if (d != 3)
        printf("%d", d);
}

void *thread(void *vargp) {
    //此处不能直接引用i的地址，有可能导致，主线程连续的创建完所有线程后，各个线程才被调度，然后i的值已经为10，此时，再调度各个输出函数
    //输出的结果就都是第10个字符串了，而且由于此时i=10，访问的字符串数组位置非法，引发数组越界，可能导致一些列问题
    int myid = (int) vargp;
    static int cnt = 0;
    printf("[%d]: %s (cnt=%d)\n", myid, ptr[myid], ++cnt);
    return NULL;
}

int main() {
    printf("Hello, World!\n");
    fun1();
    fu();
    fun1();
    pthread_t tid;
    char *msgs[10] = {
            "Hello from foo",
            "Hello from bar"
            };
    ptr = msgs;
    int i;

    for (i = 0; i < 10; i++)
        pthread_create(&tid, NULL, thread, (void *) i);//此处不能使用(void *) &i传递参数，会由于并发执行导致参数错误，并引发越界
    pthread_exit(NULL);
    return 0;
}
