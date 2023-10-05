#include <iostream>
#include <list>

using  namespace  std;
class test{
public:
    void fun1(const int* a){
        cout<<"111"<<endl;
    }
    void fun1(int* const b){
        cout<<"111"<<endl;
    }
    int a1;
protected:
    void fun2(){
        cout<<"22"<<endl;
    }
    int a2;
};
class ttt: protected test{
public:
    void fun3(){
        cout<<"333"<<endl;
        cout<<a1<<" "<<a2<<endl;
    }
};
int main() {
    ttt a;
    string  s="strsahudhastr";
    int pos=0;
    while (pos<s.length())
    {
        pos=s.find("str",pos);
        cout<<pos<<endl;
        pos++;
    }

    //a.fun3();
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
