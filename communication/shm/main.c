#include <stdio.h>
#include "sys/shm.h"
#include "string.h"
#include "semaphore.h"
#include "fcntl.h"
#define SHM_SIZE 256
#define SHM_KEY  6
#define BUFF_MAX_SIZE 100

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
    int shmid;
    struct shm_control sender;
    void *share_memory;
    sem_t *shm_read_send,*shm_write,*shm_read_rcv;
    sem_unlink("shm_read_rcv");
    sem_unlink("shm_read_send");
    sem_unlink("shm_write");
    shm_read_send=sem_open("shm_read_send",O_CREAT,0666,0);
    shm_read_rcv=sem_open("shm_read_rcv",O_CREAT,0666,0);
    shm_write= sem_open("shm_write",O_CREAT,0666,1);
    shmid= shmget(SHM_KEY,SHM_SIZE,IPC_CREAT|0666);
    share_memory=(struct shm_control*) shmat(shmid,0,0);

    printf("Memory is at %X\n",(int)share_memory);
    scanf("%s",sender.shm_buff);
    sender.shmType=send_to_rcv;
    sem_wait(shm_write);
    memcpy(share_memory,&sender, sizeof(sender));
    sem_post(shm_write);
    sem_post(shm_read_rcv);

    sem_wait(shm_read_send);
    memcpy(&sender, share_memory,sizeof(sender));
    if(sender.shmType==rcv_to_send)
        printf("sender get data:%s",sender.shm_buff);

    int err;
    err=shmdt(share_memory);
    if(err==-1)
        printf("delete failed!\n");
    shmctl(shmid,IPC_RMID,0);
    sem_close("shm_read_rcv");
    sem_close("shm_read_send");
    sem_close("shm_write");
    return 0;
}
