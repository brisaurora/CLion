#include <stdio.h>
#include "sys/shm.h"
#include "string.h"
#include "semaphore.h"
#define SHM_SIZE 256
#define SHM_KEY  6
#define BUFF_MAX_SIZE 100
int main() {
    int shmid;
    char shm_buff[BUFF_MAX_SIZE+1];
    char *share_memory;

    shmid= shmget(SHM_KEY,SHM_SIZE,IPC_CREAT|0666);
    share_memory=(char *) shmat(shmid,0,0);

    printf("Memory is at %X %X %X\n",(int)share_memory,(int)(*share_memory),(int)(&share_memory));
    scanf("%s",shm_buff);

    strncpy(share_memory,shm_buff, strlen(shm_buff)+1);

    ///////////////////////////
    char *test_memory;
    char test_buff[BUFF_MAX_SIZE+1];
    int test_id;
    test_id= shmget(SHM_KEY,0,IPC_CREAT|0666);
    //test_memory=(char *) shmat(test_id,0,0);
    test_memory=share_memory;
    printf("Memory is at %X %X %X\n",(int)test_memory,(int )(*test_memory),(int )(&test_memory));
    strncpy(test_buff,test_memory,BUFF_MAX_SIZE);
    printf("%s",test_buff);
    //shmdt(test_memory);
    ///////////////////////////////////
    int err;
    err=shmdt(share_memory);
    if(err==-1)
        printf("delete failed!\n");
    shmctl(shmid,IPC_RMID,0);


    return 0;
}
