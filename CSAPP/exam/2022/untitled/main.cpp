
using namespace std;
#include <iostream>
#include<stdio.h>
#include<math.h>
#pragma warning(disable : 4996)
/// <summary>
/// ȷ��ip��ַ����
/// </summary>
/// <param name="num"></param>
/// <returns></returns>
char TypeIP(int num)
{
    char a;
    if (1 <= num && num <= 127)
    {
        cout << "��������ɵ�����A��IP��ַ" << endl;
        a = 'A'; return a;
    }
    else if (128 <= num && num <= 191)
    {
        cout << "��������ɵ�����B��IP��ַ" << endl;
        a = 'B'; return a;
    }
    else if (192 <= num && num <= 255)
    {
        cout << "��������ɵ�����C��IP��ַ" << endl;
        a = 'C'; return a;
    }
    else
        {

}
}

/// <summary>
///10����ת��Ϊ2����
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
/// 2����ת��10����
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
/// ������
/// </summary>
/// <param name="a">ip����λ</param>
/// <param name="b">����λ</param>
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
    int d1, d2, d3, d4;/*ip��ַ��1234λ����*/
    d1 = 1; d2 = d3 = d4 = 0;
    int d4s, d2s, d3s;
    d2s = d3s = d4s = 0;
    char Type; /*����ڼ���ip����*/
    int a[9] = { 0 };/*����ԭip�еĵ�һ������λ��2����*/
    int sumip = 0;/*������������*/
    int b[9] = { 0 };/*��Ӧ���������8λ*/
    int c[9] = { 0 };
    cout << "******************������ip��ַ***************\n";
    while (1)
    {
        scanf("%d.%d.%d.%d", &d1, &d2, &d3, &d4);
        if (d1 >= 1 && d2 >= 0 && d3 >= 0 && d4 >= 0 && d1 < 255 && d2 < 255 && d3 < 255 && d4 < 255)
        {
            break;
        }
        else cout << " ����������������� ����192.168.1.1\n";
    }
    cout << "********************������Ҫ����������������Χ��0-255��*******************" << endl;
    while (1)
    {
        cin >> sumip;
        if (sumip >= 0 && sumip < 255)
        {
            break;
        }
        else cout << " ������������������������롣������" << endl;
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


    /*cout << "ԭ��j��������" << endl;
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
    /*cout << endl << "ip����2����" << endl;
    for (int j = 7; j >= 0; j--)
    {
        cout << a[j] << " ";
    }*/
    And(a, b);/*������*/
    /*cout << endl << "������j��������" << endl;
    for (int j = 7; j >= 0; j--)
    {
        cout << b[j] << " ";
    }*/
    int CompID = covert2(b);//������������ID
    int computerID = covert2(c);//������λ���������ip
    /*************��������***********************/
    cout << "�����������Ϣ���Ի���" << pow(2, INsumip) << "�ֵ�ַ:" << endl;
    switch (Type)
    {
        case 'A':
            d2s = CompID + pow(2, 8 - INsumip);
            for (int m = 0; m < pow(2, INsumip); m++)
            {
                printf("%3d.%3d.%3d.%3d", d1, d2s * m, d3, d4);
                cout << "    �㲥����      ";
                printf("%3d.%3d.%3d.%3d", d1, d2s * m + computerID + 1, 255, 255);
                cout << "   ����ip��Χ��      ";
                printf("%3d.%3d.%3d.%3d------%3d.%3d.%3d.%3d\n", d1, d2s * m + 1, 0, 0, d1, d2s * m + computerID, 255, 254);
            }
            break;
        case 'B':
            d3s = CompID + pow(2, 8 - INsumip);
            for (int m = 0; m < pow(2, INsumip); m++)
            {
                printf("%3d.%3d.%3d.%3d", d1, d2, d3s * m, d4);
                cout << "    �㲥����      ";
                printf("%3d.%3d.%3d.%3d", d1, d2, d3s * m + computerID + 1, 255);
                cout << "   ����ip��Χ��      ";
                printf("%3d.%3d.%3d.%3d------%3d.%3d.%3d.%3d\n", d1, d2, d3s * m + 1, 0, d1, d2, d3s * m + computerID, 254);
            }
            break;
        case 'C':
            d4s = CompID + pow(2, 8 - INsumip);
            cout << endl;
            for (int m = 0; m < pow(2, INsumip); m++)
            {
                printf("%3d.%3d.%3d.%3d", d1, d2, d3, d4s * m);
                cout << "    �㲥����      ";
                printf("%3d.%3d.%3d.%3d", d1, d2, d3, d4s * m + computerID + 1);
                cout << "   ����ip��Χ��      ";
                printf("%3d.%3d.%3d.%3d------%3d.%3d.%3d.%3d\n", d1, d2, d3, d4s * m + 1, d1, d2, d3, d4s * m + computerID);
            }
            break;
        default:break;
    }
}
