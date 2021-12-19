#include <stdio.h>
#include "pthread.h"
#include "unistd.h"
#include "semaphore.h"
#include "sys/types.h"
#include <sys/ipc.h>
#include "fcntl.h"
#include <sys/msg.h>
#include "string.h"
#define MAX_MSG_SIZE 4096
#define MAX_RCV_BUFF 6
int msgQueue_id;
int msg_current_size;
struct myMsg
{
    long int msgType;
    char msgBuff[MAX_MSG_SIZE+1];

};
enum Msg_Type
{
    block,
    send1_to_rcv,
    send2_to_rcv,
    receive_to_send1,
    receive_to_send2
};
sem_t *msg_Empty,*msg_Write,*msg_Read;
//创建消息队列
int create_msgQueue_id(int ftork_key);
//sender1线程
void *sender1_f(void *arg);
//sender2线程
void *sender2_f(void *arg);
//send1接收处理函数
int send1_solve(struct myMsg rev_Msg[],int *size);
//send2接收处理函数
int send2_solve(struct myMsg rcv_buff[],int  *size);
//获取空缓存区
int select_block_buff(struct myMsg rcv_buff[],int size);
//接收线程
void *receive_f(void *arg);


int main() {
    pthread_t sender1,sender2,receive;
    //创建信号量
    sem_unlink("msg_Read");
    sem_unlink("msg_Empty");//取消信号量连接防止因为错误退出存在的信号量
    sem_unlink("msg_Write");
    msg_Empty= sem_open("msg_Empty",O_CREAT,0666,MAX_RCV_BUFF);
    msg_Write= sem_open("msg_Write",O_CREAT,0666,1);
    msg_Read = sem_open("msg_Read",O_CREAT,0666,1);
    msg_current_size=0;
    //创建线程
    pthread_create(&sender1,NULL,sender1_f,NULL);
    pthread_create(&sender2,NULL,sender2_f,NULL);
    pthread_create(&receive,NULL,receive_f,NULL);

    //等待线程结束
    pthread_join(sender1,NULL);
    pthread_join(sender2,NULL);
    pthread_join(receive,NULL);
    //删除消息队列
    msgctl(msgQueue_id,IPC_RMID,NULL);
    return 0;
}

//创建消息队列
int create_msgQueue_id(int ftork_key)
{
    int msgQ_id;
    key_t msgKey;
    msgKey= ftok("../MsgQueue",ftork_key);
    if(msgKey==-1)
    {
        printf("key create error!\n");
        return -1;
    }

    msgQ_id= msgget(msgKey,0666|IPC_CREAT);
    msgctl(msgQ_id,IPC_RMID,NULL);
    msgQ_id= msgget(msgKey,0666|IPC_CREAT);
    if(msgQ_id==-1)
    {
        printf("msg queue create error");
        return -1;
    }
    printf("msg queue create success:%d!\n",msgQ_id);
    return msgQ_id;
}
//sender1线程
void *sender1_f(void *arg)
{
    printf("sender1 create!\n");
    struct  myMsg send1_Msg;
    int msgKey;
    int err;
    msgKey=8;
    msgQueue_id=create_msgQueue_id(msgKey);
    while (1)
    {
        memset(&send1_Msg,0,sizeof(struct myMsg));
        scanf("%s",send1_Msg.msgBuff);
        fflush(stdin);
        fflush(stdout);
        send1_Msg.msgType=send1_to_rcv;
        sem_wait(msg_Empty);
        sem_wait(msg_Write);
        if(!strcmp(send1_Msg.msgBuff,"exit"))
        {
            memset(&send1_Msg,0,sizeof(struct myMsg));
            strcpy(send1_Msg.msgBuff,"end1");
            send1_Msg.msgType=send1_to_rcv;
            if(msgsnd(msgQueue_id,&send1_Msg,sizeof(struct  myMsg),0)==-1)
                printf("send1 send_msg error!\n");
            sem_post(msg_Write);
            sem_post(msg_Read);
            break;
        }
        else
        {
            if(msgsnd(msgQueue_id,&send1_Msg,sizeof(struct  myMsg),0)==-1)
                printf("send1 send_msg error!\n");
        }
        sem_post(msg_Write);
        sem_post(msg_Read);
        sleep(1);
    }
    while (1)
    {
        printf("send1 prepare to exit!\n");
        sem_wait(msg_Read);
        if(-1!=(msgrcv(msgQueue_id,&send1_Msg,sizeof(send1_Msg),receive_to_send1,IPC_NOWAIT))) {
            printf("send1 get receive msg is:%s", send1_Msg.msgBuff);
            sem_post(msg_Empty);
            break;
        } else
            sem_post(msg_Read);
        sleep(3);
    }

    pthread_exit(NULL);
}
//sender2线程
void *sender2_f(void *arg)
{
    printf("sender2 create!\n");
    struct  myMsg send2_Msg;

    while (1)
    {
        memset(&send2_Msg,0,sizeof(struct myMsg));
        scanf("%s",send2_Msg.msgBuff);
        send2_Msg.msgType=send2_to_rcv;
        fflush(stdin);
        fflush(stdout);
        sem_wait(msg_Empty);
        sem_wait(msg_Write);
        if(!strcmp(send2_Msg.msgBuff,"exit"))
        {
            memset(&send2_Msg,0,sizeof(struct myMsg));
            strcpy(send2_Msg.msgBuff,"end2");
            send2_Msg.msgType=send2_to_rcv;
            if(msgsnd(msgQueue_id,&send2_Msg,sizeof(struct  myMsg),0)==-1)
                printf("send2 send_msg error!\n");
            sem_post(msg_Write);
            sem_post(msg_Read);
            break;
        }
        else
        {
            if(msgsnd(msgQueue_id,&send2_Msg,sizeof(struct  myMsg),0)==-1)
                printf("send2 send_msg error!\n");
        }
        sem_post(msg_Write);
        sem_post(msg_Read);
        sleep(1);
    }
    while (1)
    {
        sem_wait(msg_Read);
        if(-1!=(msgrcv(msgQueue_id,&send2_Msg,sizeof(send2_Msg),receive_to_send2,IPC_NOWAIT))) {
            printf("send2 get receive msg is:%s", send2_Msg.msgBuff);
            sem_post(msg_Empty);
            break;
        }
        else
            printf("send2 prepare to exit!\n");
        sem_post(msg_Read);
        sleep(3);
    }

    pthread_exit(NULL);
}
//send1接收处理函数
int send1_solve(struct myMsg rev_Msg[],int *size)
{
    int i;
    struct  myMsg send_Msg;
    for(i=0;i<MAX_RCV_BUFF;i++)
    {
        if(rev_Msg[i].msgType!=send1_to_rcv)
            continue;
        if(strcmp(rev_Msg[i].msgBuff,"end1")==0)
        {
            printf("send1 msg receive:%s\n",rev_Msg[i].msgBuff);
            printf("try send over1\n");
            send_Msg.msgType=receive_to_send1;
            strcpy(send_Msg.msgBuff,"over1\n");
            sem_wait(msg_Empty);
            sem_wait(msg_Write);
            msgsnd(msgQueue_id,&send_Msg,sizeof (struct myMsg),0);
            rev_Msg[i].msgType=block;
            (*size)--;
            sem_post(msg_Write);
            sem_post(msg_Read);
            return 1;
        }
        else
            printf("send1 msg receive:%s\n",rev_Msg[i].msgBuff);
        rev_Msg[i].msgType=block;
        (*size)--;
    }
    return 0;
}
//send2接收处理函数
int send2_solve(struct myMsg rcv_buff[],int  *size)
{
    int i;
    struct  myMsg send_Msg;
    for(i=0;i<=MAX_RCV_BUFF;i++) {
        if (rcv_buff[i].msgType != send2_to_rcv)
            continue;
        if (strcmp(rcv_buff[i].msgBuff, "end2") == 0) {
            printf("send2 msg receive:%s\n", rcv_buff[i].msgBuff);
            printf("try send over2\n");
            send_Msg.msgType = receive_to_send2;
            strcpy(send_Msg.msgBuff, "over2");
            sem_wait(msg_Empty);
            sem_wait(msg_Write);
            msgsnd(msgQueue_id, &send_Msg, sizeof(struct myMsg), 0);
            (*size)--;
            rcv_buff[i].msgType=block;
            sem_post(msg_Write);
            sem_post(msg_Read);
            return 1;
        } else
            printf("send2 msg receive:%s\n", rcv_buff[i].msgBuff);
        (*size)--;
        rcv_buff[i].msgType=block;
    }

    return 0;
}
//获取空缓存区
int select_block_buff(struct myMsg rcv_buff[],int size)
{
    int i;
    for(i=0;i<size;i++)
        if(rcv_buff[i].msgType==block)
            return i;
    return i;
}
//接收线程
void *receive_f(void *arg)
{
    printf("receive create!\n");
    int size=0,i;
    struct myMsg rev_Msg[MAX_RCV_BUFF];
    struct myMsg send_Msg;
    int end=0;
    while (end<2)
    {

        fflush(stdin);
        fflush(stdout);
        memset(&rev_Msg,0,sizeof(rev_Msg));
        sem_wait(msg_Read);
        while(1)
        {
            if(size>=MAX_RCV_BUFF)
                break;
            i=select_block_buff(rev_Msg,MAX_RCV_BUFF);
            if(msgrcv(msgQueue_id,&rev_Msg[i],sizeof(struct myMsg),send1_to_rcv,IPC_NOWAIT)==-1) {
                sem_post(msg_Read);
                break;
            }
            else {
                sem_post(msg_Empty);
            }
            size++;
        }
        while(1)
        {
            if(size>=MAX_RCV_BUFF)
                break;
            i=select_block_buff(rev_Msg,MAX_RCV_BUFF);
            if(msgrcv(msgQueue_id,&rev_Msg[i],sizeof(struct myMsg),send2_to_rcv,IPC_NOWAIT)==-1)
                break;
            else
                sem_post(msg_Empty);
            size++;
        }
        for(i=1;i<size;i++)
            sem_wait(msg_Read);
        if(size==1)
            sem_post(msg_Read);
        end+= send1_solve(rev_Msg,&size);
        end+= send2_solve(rev_Msg,&size);

    }
    printf("receive already exit!\n");

    pthread_exit(NULL);
}