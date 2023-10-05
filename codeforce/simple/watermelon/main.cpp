#include <iostream>
#include "bits/stdc++.h"
using namespace std;
class A
{
public:
    void fun(string &s)
    {
        cout<<"A";
    }
    void fun(string s)
    {
        cout<<"A";
    }
};
int main() {
    int n;
    //int sum[100002],data[100002],dp[100002][100002];
    int data,begin,maxans,end,tmp_st,sum;
    int i;
    cin>>n;
    int count=1;
    while (n--)
    {
        int size;
        cin>>size;
        sum=tmp_st=begin=end=0;
        maxans=-1001;
        for(i=0;i<size;i++)
        {
            scanf("%d",&data);
            if(sum>=0)
                sum+=data;
            else
            {
                sum=data;
                tmp_st=i;
            }
            if(sum>maxans)
            {
                maxans=sum;
                begin=tmp_st+1;
                end=i+1;
            }
        }


        printf("Case %d:\n",count++);
        printf("%d %d %d\n",maxans,begin,end);
        if(n)
            printf("\n");
    }
    return 0;
}
