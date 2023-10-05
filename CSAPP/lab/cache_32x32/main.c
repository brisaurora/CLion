#include <stdio.h>
void fun(int M,int  N,int A[M][N],int B[M][N])
{
    int base_i,base_j;
    int i,j;
    int add_i,add_j;
    int a0,a1,a2,a3,a4,a5,a6,a7;
    for(base_i=0;base_i<M;base_i+=8)
        for(base_j=0;base_j<N;base_j+=8)
        {
            for(i=0;i<8;i++)
            {
                add_i=base_i+i;
                add_j=base_j+i;
                a0=A[add_i][base_j];
                a1=A[add_i][base_j+1];
                a2=A[add_i][base_j+2];
                a3=A[add_i][base_j+3];
                a4=A[add_i][base_j+4];
                a5=A[add_i][base_j+5];
                a6=A[add_i][base_j+6];
                a7=A[add_i][base_j+7];
                B[add_j][base_i]=a0;
                B[add_j][base_i+1]=a1;
                B[add_j][base_i+2]=a2;
                B[add_j][base_i+3]=a3;
                B[add_j][base_i+4]=a4;
                B[add_j][base_i+5]=a5;
                B[add_j][base_i+6]=a6;
                B[add_j][base_i+7]=a7;
            }
            for(i=0;i<8;i++)
                for(j=i+1;j<8;j++)
                {
                    a0=B[base_j+i][base_i+j];
                    B[base_j+i][base_i+j]=B[base_j+j][base_i+i];
                    B[base_j+j][base_i+i]=a0;
                }
        }

}
int main() {


    return 0;
}
