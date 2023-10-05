#include <stdio.h>
#include "windows.h"
#include<time.h>
clock_t start1, end1;
double val[1024*1024][100];
double image[1024*1024][1080];
int main() {
    int i,j;

    DWORD start,end;
    start= GetTickCount();
    start1= clock();
    for(i=1;i<102400;i++)
    {
        int x,y,z;

        for(j=1;j<99;j+=4)
        {
            x=j+1;y=j+2;z=j+3;
//            val[i][j]=image[i][j]*4-image[i-1][j]-image[i+1][j]-image[i][j+1]-image[i][j-1];
//            val[i][j+1]=image[i][j+1]*4-image[i-1][j+1]-image[i+1][j+1]-image[i][j+2]-image[i][j];
//            val[i][j+2]=image[i][j+2]*4-image[i-1][j+2]-image[i+1][j+2]-image[i][j+3]-image[i][j+1];
//            val[i][j+3]=image[i][j+3]*4-image[i-1][j+3]-image[i+1][j+3]-image[i][j+4]-image[i][j+2];
            val[i][j]=image[i][j]*4-image[i-1][j]-image[i+1][j]-image[i][x]-image[i][j-1];
            val[i][x]=image[i][x]*4-image[i-1][x]-image[i+1][x]-image[i][y]-image[i][j];
            val[i][y]=image[i][y]*4-image[i-1][y]-image[i+1][y]-image[i][z]-image[i][x];
            val[i][z]=image[i][z]*4-image[i-1][z]-image[i+1][z]-image[i][j+4]-image[i][y];

        }
        //for(j;j<1080;j++)
          //  val[i][j]=image[i][j]*4-image[i-1][j]-image[i+1][j]-image[i][j+1]-image[i][j-1];
    }
//    double c;
//    for(i=0;i<102400-2;i++)
//    {
//        for(j=0;j<99;j++)
//        {
//            //c=image[i][j+1]+image[i][j-1];
//            //val[i][j]=image[i][j]*4-image[i-1][j]-image[i+1][j]-c;
//            val[i][j]=image[i][j]*4-image[i-1][j]-image[i+1][j]-image[i][j+1]+image[i][j-1];
//            //val[i][j]=image[i][j]*4-image[i][j+1]+image[i][j-1];
//
//        }
//    }
    end= GetTickCount();
    end1= clock();
    printf("time=%lu %lu\n",end-start,end1-start1);
    printf("Hello, World!\n");
    return 0;
}
