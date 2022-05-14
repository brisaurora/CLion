
#include <iostream>
#include <string>
#include "math.h"
using namespace std;
union test
{
    double k;
    int t[3];
};
struct S2{
    int i;
    int j;
    char b;
};
struct S3{
    char i;
    long long k;
    char b;
    int e;
    char d[];
};
//main
int main()
{
    S3 D;
    char y[2]="2";
    cout<< sizeof(S3)<<" "<<D.d<<" "<<&D.d<<&y<<endl;
    string empty("");
    string name("hehehehehehehee");
    cout<<"name:"<<name.capacity()<<" "<<name.length()<<" "<<name.max_size()<<endl;
    name="hehehehehehehee22hehehehehehehee22";
    name="123";

    string longstr("dfaaaaaaaxaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    name.resize(3);
    cout<<"name:"<<name.capacity()<<" "<<name.length()<<" "<<name.max_size()<<endl;
    int *a= (int *)malloc(sizeof(int ));

    short *ax= (short *)malloc(sizeof(short ));
    char *ax1= (char *)malloc(sizeof(char ));
    *ax=*ax+*ax1;
/*    for(auto &c:longstr)
    {
        printf("c：%p\n", &c);
    }*/
    cout << sizeof("hehehehehehehee") << " ";
    cout <<" "<< sizeof(name) ;
    cout <<" " <<sizeof(longstr) ;
    cout << " "<<sizeof(string)<<" " ;
    cout<< sizeof(union test)<<endl;

    struct S2 T,*p;
    p=&T;
    cout<< sizeof(T)<<endl;
    cout<< p<<endl;
    struct S3 Tt,*pp;
    pp=&Tt;
    cout<< sizeof(Tt)<<endl;
    cout<< pp<<endl;

    //system("pause");
    return 0;
}