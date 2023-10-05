#include <stdio.h>
#include <process.h>
#include "math.h"
void transpose_submit(int M, int N, int A[N][M], int B[M][N]);

int main() {
    int A[61][67],B[61][67];
    transpose_submit(61,67,A,B);
    double k=1;
    k= k/0;
    double t=1;
    t=t/(-0);
    k= t/k;
    printf("\n %lf %lf\n",k,t);
    printf("Hello, World!\n");
    system("PAUSE");
    return 0;
}
void transpose_submit(int M, int N, int A[N][M], int B[M][N])
{
    int base_i,base_j;
    int i,j;
    int add_i,add_j;
    int a0,a1,a2,a3,a4,a5,a6,a7;
    int m=M/8*8;
    int n=N/8*8;
    {
        for(base_i=0;base_i<m;base_i+=8)
            for(base_j=0;base_j<n;base_j+=8)
            {
                //搬动前4行
                for(i=0;i<4;i++)
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
                //转置B四行
                for(i=0;i<4;i++)
                    for(j=i+1;j<4;j++)
                    {
                        add_i=base_i;add_j=base_j;
                        a0=B[add_j+i][add_i+j];
                        B[add_j+i][add_i+j]=B[add_j+j][add_i+i];
                        B[add_j+j][add_i+i]=a0;
                    }
                for(i=0;i<4;i++)
                    for(j=i+1;j<4;j++)
                    {
                        add_i=base_i+4;add_j=base_j;
                        a0=B[add_j+i][add_i+j];
                        B[add_j+i][add_i+j]=B[add_j+j][add_i+i];
                        B[add_j+j][add_i+i]=a0;
                    }

                //移动对应的块到对应位置
                for(i=0;i<4;i++)
                {
                    add_j=base_j+i;
                    add_i=base_i+4;
                    a0=B[add_j][base_i+4];
                    a1=B[add_j][base_i+5];
                    a2=B[add_j][base_i+6];
                    a3=B[add_j][base_i+7];
                    B[add_j][base_i+4]=A[base_i+4][add_j];
                    B[add_j][base_i+5]=A[base_i+5][add_j];
                    B[add_j][base_i+6]=A[base_i+6][add_j];
                    B[add_j][base_i+7]=A[base_i+7][add_j];
                    B[add_j+4][base_i]=a0;
                    B[add_j+4][base_i+1]=a1;
                    B[add_j+4][base_i+2]=a2;
                    B[add_j+4][base_i+3]=a3;
                }
                for(i=0;i<4;i++)
                {
                    add_j=base_j+4+i;
                    add_i=base_i;
                    B[add_j][add_i+4]=A[add_i+4][add_j];
                    B[add_j][add_i+5]=A[add_i+5][add_j];
                    B[add_j][add_i+6]=A[add_i+6][add_j];
                    B[add_j][add_i+7]=A[add_i+7][add_j];

                }
            }
    }
    B[0][56]=A[56][0];
    printf("%d %d",m,n);
    for(i=n;i<M;i++)
        for(j=0;j<N;j++) {
            a0 = A[i][j];
            B[j][i]=a0;
        }
    /*for(i=0;i<M;i++)
            for(j=n;j<N;j++)
            {
                a0 = A[i][j];
                B[j][i]=a0;
            }*/

    /*for(base_i=0;base_i<M;base_i+=1)
           {
           for(base_j=0;base_j<N;base_j+=1)
           if(A[i][j]!=B[j][i])
               printf("(%d %d) \n",i,j);
       }*/

}