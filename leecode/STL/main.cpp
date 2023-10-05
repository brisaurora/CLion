#include <iostream>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;
class A{
public:
    void fun(){
        int c=1;
        cout<<"this is A"<<endl;
    }
};
class B:public A{
public:
    int t;
    void fun1(){
        int c=1;
        cout<<"this is B"<<endl;
        t=1;
    }
};
int main() {
    map<int,int> t;
    vector<int> nums={2,2,3,2};
    int i;
    for(i=0;i<nums.size();i++)
    {
        if(t.count(nums[i])==0)
            t[nums[i]]=1;
        else
            t[nums[i]]++;

    }
    map<int,int >::iterator it;
    int answer;double k;
    B d;
    A & val2=d;
    d.fun1();
    int *p;
    for(it=t.begin();it!=t.end();it++)
    {
        cout<<it->first<<it->second<<endl;
       // cout<<1<<endl;
        if(it->second==1)
        {
            answer=it->first;
            break;
        }
    }
    return answer;
    return 0;
}
