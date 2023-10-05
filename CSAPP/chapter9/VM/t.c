#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
	char *p,*p1,*p2,*p3;
	int n=1024*1*1024*1000;
	fork();
	p=(char *)malloc(n);
	p1=(char *)malloc(n);
	p2=(char *)malloc(n);
	p3=(char *)malloc(n);
	if(!p)
	   printf("error!\n");
	else
	   printf("%p\n",p);
	int i=0;
	while(1){
             if(i<n)
		i++;
	      else
		i=0;
	   *(p+i)=i%13;
	   *(p1+i)=i%13;
	   *(p2+i)=i%13;
	   *(p3+i)=i%13;
	}
	return 0;
}
