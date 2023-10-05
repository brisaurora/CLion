#include <iostream>
#include<bits/stdc++.h>
using namespace  std;
//求最大连续递增数字串（如“ads3sl456789DF3456ld345AA”中的“456789”）
int main() {
    string str;
    vector<int> data;
    cin>>str;
    int i;
    for(i=0;i<str.size();i++)
    {
        if(str[i]>='0'&&str[i]<='9')
            data.push_back(str[i]-'0');
    }
    int j,size=data.size();
    int *dp=(int *) malloc(sizeof(int)*data.size());
    memset(dp,0,size* sizeof(int));
    dp[0]=1;
    int answer=1;
    for(i=0;i<size;i++)
    {
        for(j=0;j<i;j++)
        {
            if(data[i]>data[j])
                dp[i]=max(dp[i],dp[j]+1);
        }
        answer=max(answer,dp[i]);
    }

    cout<<answer<<endl;


    return 0;
}
