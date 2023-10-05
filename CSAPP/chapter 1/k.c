#include<stdio.h>
#include<string.h>
void copy(char str1[],char str[])
{
    strcpy(str1,str);
    puts(str1);
      
}
int main()
{
   char str[10]="hello";
   char str1[11]="klly";
    char *p=str;
   copy(str1,str);
   return 0;

}
