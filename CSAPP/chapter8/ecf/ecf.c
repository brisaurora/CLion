#include<stdio.h>
#include<sys/syscall.h>
#include <unistd.h>
#include <signal.h>
void sig(int signum)
{
	static int i=0;
	printf("我收到了Ctrl+c信号 %d\n",i++);
}
static int value_assignment(int input) {
  int ret = 0;

  asm volatile(
    /* ret = input */
    "movl %1, %0\n" /* 通过占位符指定交互的变量 ： %0:ret %1:input*/
    :"=r"(ret) 
    :"r"(input)
  );

  return ret;
}

int main() {
  int input = 1,k=29;
  int ret = value_assignment(input);
  signal(SIGINT,sig);
  asm volatile(
    /* ret = input */
    "movl $29, %%eax\n"
    "movl %%eax, %0\n" /* 通过占位符指定交互的变量 ： %0:ret %1:input*/
    "int $128\n"
    :"=r"(ret),"=r"(k)
    :"r"(k),"r"(input)
    :"%rax"
  );
  //pause();
  write(1,"hello\n",7);
//  _exit(0);
  printf("input = %d\n", input);
  printf("ret = %d\n", ret);
  printf("k = %d\n", k);
  return 0;
}
