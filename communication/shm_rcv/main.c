#include <stdio.h>
#include "semaphore.h"
#include "fcntl.h"
#include "sys/shm.h"
#include "stdlib.h"
#include "string.h"
#define BUFF_MAX_SIZE 200
#define SHM_KEY 6
enum
{
    block,
    rcv_to_send,
    send_to_rcv
};
struct shm_control
{
    int shmType;
    char shm_buff[BUFF_MAX_SIZE+1];
};
int main() {

    void *rcv_shm_memory;
    struct shm_control rcv;
    sem_t *shm_read_send,*shm_write,*shm_read_rcv;
    shm_read_send=sem_open("shm_read_send",O_RDWR);
    shm_read_rcv=sem_open("shm_read_rcv",O_RDWR);
    shm_write= sem_open("shm_write",O_RDWR);
    int shm_id;
    shm_id= shmget(SHM_KEY,0,IPC_CREAT|0666);
    rcv_shm_memory=(struct shm_control*) shmat(shm_id,0,0);
    printf("Memory is at %X\n",(int)rcv_shm_memory);

    sem_wait(shm_read_rcv);
    sem_wait(shm_write);
    memcpy(&rcv,rcv_shm_memory,sizeof(rcv));
    if(rcv.shmType==send_to_rcv)
    {
        printf("rcv get data is:%s\n",rcv.shm_buff);
    }
    strcpy(rcv.shm_buff,"over");
    rcv.shmType=rcv_to_send;
    memcpy(rcv_shm_memory,&rcv,sizeof(rcv));
    sem_post(shm_write);
    sem_post(shm_read_send);
    shmdt(rcv_shm_memory);
    return 0;
}
