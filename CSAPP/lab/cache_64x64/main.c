#include <stdio.h>
int borrow_block_index(int i)
{
    if(i==0) return 1;
    else return 0;
}
void init(int M, int N, int A[N][M])
{
    int i,j;
    for(i=0;i<8;i++)
        for(j=0;j<8;j++)
            A[i][j]=i*11+j;
}
void show(int M, int N, int A[N][M])
{
    int i,j;
    for(i=0;i<8;i++) {
        for (j = 0; j < 8; j++)
            printf("%d ", A[i][j]);
        printf("\n");
    }
}
void transpose_submit(int M, int N, int A[N][M], int B[M][N])
{
    int base_i,base_j;
    int i,j;
    int add_i,add_j;
    int a0,a1,a2,a3,a4,a5,a6,a7;

    for(base_i=0;base_i<M;base_i+=8)
        for(base_j=0;base_j<N;base_j+=8)
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
    /* for(base_i=0;base_i<M;base_i+=1)
            {
            for(base_j=0;base_j<N;base_j+=1)
            if(A[i][j]!=B[j][i])
                printf("(%d %d) ",i,j);
            else
                printf("0 ");
            printf("\n");
        }*/

}
int main() {
    int A[8][8];
    int B[8][8];
    init(8,8,A);
 //   show(8,8,A);
    printf("Hello, World!\n");
    transpose_submit(8,8,A,B);
   // show(8,8,B);
    return 0;
}
