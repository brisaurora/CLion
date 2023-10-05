
using namespace std;
#include <iostream>
#include<stdio.h>
#include<math.h>
#pragma warning(disable : 4996)
/// <summary>
/// 确定ip地址类型
/// </summary>
/// <param name="num"></param>
/// <returns></returns>
char TypeIP(int num)
{
    char a;
    if (1 <= num && num <= 127)
    {
        cout << "根据输入可得这是A类IP地址" << endl;
        a = 'A'; return a;
    }
    else if (128 <= num && num <= 191)
    {
        cout << "根据输入可得这是B类IP地址" << endl;
        a = 'B'; return a;
    }
    else if (192 <= num && num <= 255)
    {
        cout << "根据输入可得这是C类IP地址" << endl;
        a = 'C'; return a;
    }
    else
        {

}
}

/// <summary>
///10进制转换为2进制
/// </summary>
/// <param name="d"></param>
/// <param name="b"></param>
void convert(int d, int b[8])
{
    int i = 0, j, n;
    b[8] = { 0 };
    while (d > 0)
    {
        n = d % 2;
        d = d / 2;
        b[i++] = n;
    }
}
/// <summary>
/// 2进制转换10进制
/// </summary>
/// <param name="a"></param>
/// <returns></returns>
int	covert2(int a[8])
{
    int numb = 0;
    for (int j = 7; j >= 0; j--)
    {
        numb += a[j] * pow(2, j);
    }
    return numb;
}

/// <summary>
/// 与运算
/// </summary>
/// <param name="a">ip主机位</param>
/// <param name="b">掩码位</param>
void And(int a[8], int b[8])
{
    for (int j = 7; j >= 0; j--)
    {
        if (a[j] == 1 && b[j] == 1)
        {
            b[j] = 1;
        }
        else
        {
            b[j] = 0;
        }
    }
}

int main()
{
    int d1, d2, d3, d4;/*ip地址第1234位数字*/
    d1 = 1; d2 = d3 = d4 = 0;
    int d4s, d2s, d3s;
    d2s = d3s = d4s = 0;
    char Type; /*储存第几种ip类型*/
    int a[9] = { 0 };/*储存原ip中的第一个主机位的2进制*/
    int sumip = 0;/*划分子网个数*/
    int b[9] = { 0 };/*对应子网掩码的8位*/
    int c[9] = { 0 };
    cout << "******************请输入ip地址***************\n";
    while (1)
    {
        scanf("%d.%d.%d.%d", &d1, &d2, &d3, &d4);
        if (d1 >= 1 && d2 >= 0 && d3 >= 0 && d4 >= 0 && d1 < 255 && d2 < 255 && d3 < 255 && d4 < 255)
        {
            break;
        }
        else cout << " 输入错误请重新输入 例如192.168.1.1\n";
    }
    cout << "********************请输入要划分子网的数量范围（0-255）*******************" << endl;
    while (1)
    {
        cin >> sumip;
        if (sumip >= 0 && sumip < 255)
        {
            break;
        }
        else cout << " 划分数量输入错误请重新输入。。。。" << endl;
    }
    int  INsumip = ceil(log2(sumip));
    //cout << sumip << endl;
    for (int k = 7; k >= INsumip; k--)
    {
        b[k] = 1;
    }
    for (int k = 0; k <= 7 - INsumip; k++)
    {
        c[k] = 1;
    }
    c[0] = 0;


    /*cout << "原来j子网掩码" << endl;
    for (int j = 7; j >= 0; j--)
    {
        cout << b[j] << " ";
    }*/

    //printf("%3d.%3d.%3d.%3d\n", d1, d2, d3, d4);
    Type = TypeIP(d1);
    switch (Type)
    {
        case 'A': convert(d2, a); break;
        case 'B': convert(d3, a); break;
        case 'C': convert(d4, a); break;
        default:
            break;
    }
    /*cout << endl << "ip子网2进制" << endl;
    for (int j = 7; j >= 0; j--)
    {
        cout << a[j] << " ";
    }*/
    And(a, b);/*与运算*/
    /*cout << endl << "与运算j子网掩码" << endl;
    for (int j = 7; j >= 0; j--)
    {
        cout << b[j] << " ";
    }*/
    int CompID = covert2(b);//与运算后的主机ID
    int computerID = covert2(c);//除划分位后最大主机ip
    /*************划分子网***********************/
    cout << "根据输入的信息可以划分" << pow(2, INsumip) << "种地址:" << endl;
    switch (Type)
    {
        case 'A':
            d2s = CompID + pow(2, 8 - INsumip);
            for (int m = 0; m < pow(2, INsumip); m++)
            {
                printf("%3d.%3d.%3d.%3d", d1, d2s * m, d3, d4);
                cout << "    广播号是      ";
                printf("%3d.%3d.%3d.%3d", d1, d2s * m + computerID + 1, 255, 255);
                cout << "   主机ip范围是      ";
                printf("%3d.%3d.%3d.%3d------%3d.%3d.%3d.%3d\n", d1, d2s * m + 1, 0, 0, d1, d2s * m + computerID, 255, 254);
            }
            break;
        case 'B':
            d3s = CompID + pow(2, 8 - INsumip);
            for (int m = 0; m < pow(2, INsumip); m++)
            {
                printf("%3d.%3d.%3d.%3d", d1, d2, d3s * m, d4);
                cout << "    广播号是      ";
                printf("%3d.%3d.%3d.%3d", d1, d2, d3s * m + computerID + 1, 255);
                cout << "   主机ip范围是      ";
                printf("%3d.%3d.%3d.%3d------%3d.%3d.%3d.%3d\n", d1, d2, d3s * m + 1, 0, d1, d2, d3s * m + computerID, 254);
            }
            break;
        case 'C':
            d4s = CompID + pow(2, 8 - INsumip);
            cout << endl;
            for (int m = 0; m < pow(2, INsumip); m++)
            {
                printf("%3d.%3d.%3d.%3d", d1, d2, d3, d4s * m);
                cout << "    广播号是      ";
                printf("%3d.%3d.%3d.%3d", d1, d2, d3, d4s * m + computerID + 1);
                cout << "   主机ip范围是      ";
                printf("%3d.%3d.%3d.%3d------%3d.%3d.%3d.%3d\n", d1, d2, d3, d4s * m + 1, d1, d2, d3, d4s * m + computerID);
            }
            break;
        default:break;
    }
}
