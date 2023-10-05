#include<bits/stdc++.h>
using namespace std;
struct item
{
    int num,weight,value;
    bool operator <(struct item a)
    {
        if(value/weight>a.value/a.weight)
            return true;
        else if(value/weight==a.value/a.weight&&num>a.num)
            return true;
        return false;
    }
};
int main()
{
    int bag_volume;
    cin>>bag_volume;
    int item_num,i,j,k;
    cin>>item_num;
    int dp[10008];
    struct item item_data[item_num];
    for(i=1;i<=item_num;i++)
    {
        cin>>item_data[i].num>>item_data[i].weight>>item_data[i].value;
    }
   // sort(item_data+1,item_data+item_num+1);
    for (i=1; i<=item_num; i++)
        for (j=bag_volume;j>=item_data[i].weight ; j--)
            for (k=0; k<=item_data[i].weight &&  k*item_data[i].weight <=j; k++)
                dp[j] = max( dp[j], dp[j - k * item_data[i].weight] + k *item_data[i].value);
    cout<<dp[bag_volume]<<endl;
    return 0;
}