#include <iostream>
#include "bits/stdc++.h"
#include "data1.h"
using namespace std;
int *z=(int*)malloc(1000);
class A {
public:
    A(int c){
        ttt=c;
    }
    A& operator =(A & data)
    {
        this->ttt=data.ttt;
        return *this;
    }
    int test()
    {
        return this->ttt;
    }

private:
    int ttt;
};
//int main() {
//    int n;
//    A c(11),d(12);
//    c=d;
//    //p=0;
//    cout<<d.test()<<endl;
//    int *a=(int *) malloc(sizeof (int )*2);
//    int i;
//    vector<int > data={1,2,7,10,11,9,12};
//    vector<int >::iterator it;
//    it=data.begin();
//    while (it!=data.end())
//    {
//        if(*it<10)
//            it=data.erase(it);
//        else
//            it++;
//    }
//    it=data.begin();
//    while (it!=data.end())
//    {
//        cout<<*it<<endl;
//        it++;
//    }
//    return 0;
//}

int main() {
    // 动态分配内存
    int**** a = new int***[129];
    for (int i = 0; i < 129; i++) {
        a[i] = new int**[129];
        for (int j = 0; j < 129; j++) {
            a[i][j] = new int*[129];
            for (int k = 0; k < 129; k++) {
                a[i][j][k] = new int[129];
            }
        }
    }

    // 使用数组
    a[0][0][0][0] = 1;
    std::cout << a[0][0][0][0] << std::endl;
    for (int i = 0; i < 129; i++) {

        for (int j = 0; j < 129; j++) {

            for (int k = 0; k < 129; k++) {
                a[i][j][k][0]=1;
            }
        }
    }

    // 释放内存
    for (int i = 0; i < 129; i++) {
        for (int j = 0; j < 129; j++) {
            for (int k = 0; k < 129; k++) {
                delete[] a[i][j][k];
            }
            delete[] a[i][j];
        }
        delete[] a[i];
    }
    delete[] a;


    return 0;
}