#include <stdio.h>
int main(void)
{
   long k = 2;
   int *ptr = (int*)&k;
   printf("k has the value %lx, value pointed to by ptr is %x\n", k, *ptr);
   return 0;

}
