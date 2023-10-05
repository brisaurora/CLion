#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int gift_a,gift_high,door_num;
    int i;
    multimap<int ,int> data;
    multimap<int ,int>::iterator it,next_it;
    int door_a;
    int door_high;
    while (cin>>gift_a>>gift_high)
    {
        cin>>door_num;

        for(i=0;i<door_num;i++)
        {
            cin>>door_a>>door_high;
            if(door_a>=gift_a)
               data.insert(pair<int,int>(door_a,door_high));
        }
        it=data.begin();
        if(data.begin()==data.end())
            return 1;
        else
            if(!data.empty())
                return 0;
        next_it=data.begin();
        next_it++;
        vector<int> min_door;
        int min_high=it->second;
        for(;next_it!=data.end();it++,next_it++)
        {
            if(it->first==next_it->first)
                min_high=min(it->second,next_it->second);
            else {
                min_door.push_back(min_high);
                min_high=next_it->second;
            }
        }
        if(it->first==next_it->first) {
            min_high = min(it->second, next_it->second);
            min_door.push_back(min_high);
        }
        else
        {
            min_door.push_back(min_high);
            min_door.push_back(next_it->second);
        }
        int j,dp[min_door.size()];
        dp[0]=1;
        //最大升序子序列
        for(i=1;i<min_door.size();i++)
        {
            for(j=0;j<i;j++)
            {
                if(min_door[i]>min_door[j])
                    dp[i]=max(dp[j]+1,dp[i-1]);
            }
        }
        cout<<dp[min_door.size()-1]<<endl;
        min_door.clear();
        data.clear();
    }
    return 0;
}
