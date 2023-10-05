#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
struct Good
{
    int begin;
    int reward;
};
int main() {
    //因为是增序运输，所以把货物按终止地址进行排序，分解成n个子问题，即，到达每一个点最大元宝数是多少
    //dp[i]=max(dp[i-1],dp[i-good[i]]+reward);
    //max(不搬运终点是这个点的货物，直接继承上一个点的元宝数，或者搬运终点是这个点的货物+奖励的元宝数）
    int n,i,tmp_end,tmp_extra,tmp_reward,tmp_begin,address;
    int dp[100010];
    struct Good tmp;
    multimap<int ,Good> data;
    multimap<int ,Good>::iterator it,tmp_it;
    while (cin>>n)
    {
        memset(dp,0, sizeof(dp));
        int k=0;
        while (cin>>tmp_begin>>tmp_end>>tmp_extra)
        {
            k++;
            tmp_reward=tmp_end-tmp_begin+tmp_extra;
            tmp.begin=tmp_begin;tmp.reward=tmp_reward;
            data.insert(pair<int,Good>(tmp_end,tmp));
            if(k==6)
                break;
        }
        for(it=data.begin();it!=data.end();it++)
        {
           cout<<tmp_it->first<<" "<<address-tmp_it->second.begin<<" "<<tmp_it->second.reward;

        }
        for(it=data.begin();it!=data.end();it++)
        {
            for(tmp_it=data.begin();it!=tmp_it;it++)
            {
                address=tmp_it->first;
                dp[address]=max(dp[address-1],dp[address-tmp_it->second.begin]+tmp_it->second.reward);
            }
        }
        cout<<dp[data.end()->first-1];

    }


    return 0;
}
