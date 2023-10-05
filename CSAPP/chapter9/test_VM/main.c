#include<stdio.h>
#include<malloc.h>
//#include<stdlib.h>
#include <string.h>
#include <math.h>
//#include<unistd.h>
//#include<sys/types.h>
#define GitHub_upload
#ifdef GitHub_upload
    #define n 100
#else
    #define n 1024*1024*1024*1
#endif
char str1[n]="12";
//char str2[n];
//char str3[n];
//char str4[n];

static int x;//错误，两个全局变量冲突
//本程序用来测试Linux和WIn10下，SWAP区的变化
//本函数测试矩阵装置
void T_Maxi(int N,int A[][N],int B[][N])
{
    int len =8;
    int i,j,a0,a1,a2,a3,a4,a5,a6,a7;
    int k,s;
    for (i = 0; i < N; i += len) {//矩阵行分块
        for (j = 0; j < N; j += len ) {//矩阵列分块
            for(k = i ,s=j; k< i+len && s <j+len; k++ ,s++){
                a0 = A[k][j + 0];//取出A每一行数据
                a1 = A[k][j + 1];
                a2 = A[k][j + 2];
                a3 = A[k][j + 3];
                a4 = A[k][j + 4];
                a5 = A[k][j + 5];
                a6 = A[k][j + 6];
                a7 = A[k][j + 7];
                B[s][i + 0] = a0;//存入B中每一行数据
                B[s][i + 1] = a1;
                B[s][i + 2] = a2;
                B[s][i + 3] = a3;
                B[s][i + 4] = a4;
                B[s][i + 5] = a5;
                B[s][i + 6] = a6;
                B[s][i + 7] = a7;
            }
            for(k = 0 ; k< len ; k++)//以【j,i】为基址进行矩阵转置运算
                for (s = k+1; s < len; s++) {
                    a0= B[j + k][i + s];
                    B[j + k][i + s] = B[j + s][i + k];
                    B[j + s][i + k]=a0;
                }

        }
    }
}
void show_ALL_Maix(int N,int A[][N],int B[][N])
{
    int i,j;
    for(i=0;i<N;i++) {
        for (j = 0; j < N; j++) {
            printf("%d ",A[i][j]);
        }
        printf(" * ");
        for (j = 0; j < N; j++) {
            printf("%d ",B[i][j]);
        }
        printf("\n");
    }

}
void show_Maix(int N,int A[][N])
{
    int i,j;
    for(i=0;i<N;i++) {
        for (j = 0; j < N; j++) {
            printf("%d ",A[i][j]);
        }
        printf(" * ");
        printf("\n");
    }
    printf("*****************\n");

}
void init_Maix(int N,int A[][N],int B[][N])
{
    int i,j;
    memset(B,0,sizeof (B[N][N]));
    memset(A,0,sizeof (A[N][N]));
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            A[i][j]=i*N+j;
}
//double l;
int main()
{
    int c1=-9;
    c1=abs(-9);
    printf("%d",c1);
    //外部符号问题
    //extern  int l;报错
    extern int l;
  //  memset(str1,1,sizeof(str1));
//    memset(str2,1,sizeof(str2));
//    memset(str3,1,sizeof(str3));
//    memset(str4,1,sizeof(str4));
    str1[n-1]='\0';//str2[n-1]='\0';str3[n-1]='\0';str4[n-1]='\0';
    //printf("%s",str);
//    while(1){
//
//    }
    //地址别名问题
    //无穷比较问题
    double  d=1e300;
    int x=(d*d)>0.0;
    printf("%d\n",x);
    int i=1,j=1,k=0;
    //d=(i++)&&(j++)||(k++);
    d=j&&i||k++;
    printf("%d %d %d %lf\n",i,j,k,d);
    //矩阵分块法测试
    int A[32][32],B[32][32];
    init_Maix(32,A,B);
    show_Maix(32,A);
    T_Maxi(32,A,B);
    show_Maix(32,B);
    //show_ALL_Maix(32,A,B);
    int N=32;
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            B[i][j]=B[i][j]-A[j][i];
    show_Maix(32,B);
    //system("PAUSE");
    //矩阵分块法测试
    return 0;
}
