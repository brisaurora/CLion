#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int divide(int a, int b) {
        int neg=0;

        if((a^b)<0)
            neg=1;
        if(a==INT_MIN)
            if(b==-1)
                return INT_MAX;
            else
                return INT_MIN;
        a=abs(a);b=abs(b);
        int stride=0,answer=0,cmp_num=b;

        while(a>=cmp_num)
        {
            stride++;
            cmp_num=cmp_num<<1;
            if(cmp_num>=(1<<30))
            {
                if(a>=cmp_num)
                    stride++;
                break;
            }

        }

        int temp=0;
        while(stride)
        {
            stride--;
            temp+=b<<stride;
            if(temp<=a)
            {
                answer+=1<<stride;
            }
            else
                temp-=b<<stride;
        }
        if(neg)
            return -answer;
        else
            return answer;
    }
};
int main() {
    int n=5;

        vector<int> answer(n+1,0);
        int temp,i;

        //answer.resize(n,0);
        for(i=0;i<=n;i++)
        {
            temp=i;
            while(temp!=0)
            {
                //cout<<temp<<(temp&1)<<endl;
                if((temp&1)==1) cout<<temp<<(temp&1)<<endl;//answer[i]=answer[i]++;
                temp=temp>>1;
            }
        }

    return 0;
}
