#include <stdio.h>
#include "bits/stdc++.h"

using namespace std;

vector<vector<vector<vector<double>>>> e;
void createArray(vector<vector<vector<vector<double>>>> &aa,int a, int b, int c, int d) {


    aa.resize(a);
    int i,j,k;
    for(i=0;i<a;i++) {
        aa[i].resize(b);
        for (j = 0; j < b; j++) {
            aa[i][j].resize(c);
            for (k = 0; k < c; k++) {
                aa[i][j][k].resize(d);
            }
        }
    }

}
int main() {
    int age;
    createArray(e,129,129,129,2);
    int i,j,k,w;

    for(i=0;i<129;i++)
        for(j=0;j<129;j++)
            for(k=0;k<129;k++)
                for(w=0;w<129;w++)
                {
                    e[i][j][k][w]=1;
                }

    return 0;
}
