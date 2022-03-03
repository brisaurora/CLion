
#include <iostream>
#include <string>
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
};
//main
int main(void )
{
    string empty("");
    string name("hehehehehehehee");

    string longstr("dfaaaaaaaxaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");

    int *a= (int *)malloc(sizeof(int ));

    short *ax= (short *)malloc(sizeof(short ));
    char *ax1= (char *)malloc(sizeof(char ));

    for(auto &c:longstr)
    {
        printf("c：%p\n", &c);
    }
    cout << sizeof("hehehehehehehee") << endl;
    cout << sizeof(name) << endl;
    cout << sizeof(longstr) << endl;
    cout << sizeof(string) << endl;
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