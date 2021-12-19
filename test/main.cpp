#include <iostream>
#include "cstring"
using namespace std;
typedef struct a
{
    short d;
    short l;
    double c;
    int a;
}aa[10];
int main() {
    a * temp=(a*) malloc(16);
    temp->d=10;
    temp->l=9;
    temp->c=-1.79e307;
    temp->a=1;
    char *test=(char *)temp;
    char k[26];
    memset(k,0,27);
    memcpy(k,temp,40);
    memcpy(temp,k,40);
    double *ky=(double* )(k+8);
    cout<<ky<< endl;
    cout<< sizeof (a)<<sizeof (aa)<<endl;
    cout<<sizeof (*temp)<<temp->d<<" "<<temp->l<<" "<<temp->c<<temp->a<<endl;
    cout<<(short )*test<<" ";
    test=test+2;
    cout<<(short )*(test)<<" ";
    test=test+4;
    cout<<(int )*(test)<<" ";
    test=test+2;
    cout<<(double )*(test)<<" ";
    test=test+8;
    cout<<(int )*(test)<<" ";
    test=test+4;
    cout<<(double )*(test)<<" ";
    test=test+4;
    cout<<(double )*(test)<<" ";
    test=test+1;
    cout<<(double )*(test)<<" ";
    FILE *file;
    file= fopen("TEST_READ","wb+");
    fseek(file,100000000,SEEK_SET);
    fwrite("aaa",3,1,file);
    return 0;
}
