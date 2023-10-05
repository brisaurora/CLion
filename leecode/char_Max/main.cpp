#include <iostream>
#include <vector>
using namespace std;
void count_num(vector<int> &a,string &str)
{
    int i;
    a.resize(30,0);
    for(i=0;i<str.size();i++)
        if((char)str[i]>='a'&&(char)str[i]<='z') a[str[i]-'a']++;
        else a[str[i]-'A']++;
}
int getMaxChar(int n,vector<int> a,int str_size)
{
    int MaxChar=0;
    int i,max=0;
    for(i=0;i<28;i++)
        if(a[i]>a[max]) max=i;
    if(a[max]+n>str_size)
    {
        MaxChar=a[max]+n-str_size;
        if(MaxChar%2==0) MaxChar=str_size;
        else MaxChar=str_size-1;
    }
    else
        MaxChar=a[max]+n;
    return MaxChar;
}
int main() {
    int n,a1,a2,a3,i;
    string str1,str2,str3;
    vector<int> a(30,0),b(30,0),c(30,0);
    int a22[100];
    printf("%d" ,sizeof(a22));
    while (cin >> n) { // 注意 while 处理多个 case
        cin>>str1>>str2>>str3;
        count_num(a,str1);count_num(b,str2);count_num(c,str3);
        a1=getMaxChar(n,a,str1.size());a2=getMaxChar(n,b,str1.size());a3=getMaxChar(n,c,str1.size());
        int answer=a1;
        if(a1==a2&&a2>a3||a1==a3&&a3>a2||a3==a2&&a2>a1||a1==a2&&a2==a3) printf("draw\n");
        else if(a1>a2&&a1>a3) printf("xiaoming\n");
        else if(a2>a1&&a2>a3) printf("xiaowang\n");
        else if(a3>a1&&a3>a2) printf("xiaoli\n");
        printf("%d %d %d",a1,a2,a3);

    }
}
// 64 位输出请用 printf("%lld")