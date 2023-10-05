#include <iostream>
#include <cstring>

using namespace std;
int visit[1010][1010];
char ice_map[1010][1010];
int n;
int max_length;
int max_area;
int tmp_area,tmp_length;
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
void dfs(int x,int y)
{
    if(x<0||y<0||y>=n||x>=n||visit[x][y]||ice_map[x][y]=='.')
        return;
    tmp_area++;
    visit[x][y]=1;
    tmp_length=tmp_length+4;
    if(x>0&&ice_map[x-1][y]=='#')
        tmp_length-=2;
    if(y>0&&ice_map[x][y-1]=='#')
        tmp_length-=2;
    visit[x][y]=1;
    int i,tx,ty;
    for(i=0;i<4;i++)
    {
        tx=x+dir[i][0];
        ty=y+dir[i][1];
        dfs(tx,ty);
    }
}
int main() {
    int i,j;
    while (cin>>n)
    {
        max_length=0;
        max_area=0;
        tmp_area=0;
        tmp_length=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
                cin>>ice_map[i][j];
        }
        memset(visit,0, sizeof(visit));
        memset(visit,0, sizeof(ice_map));
        for(i=0;i<n;i++)
            for(j=0;j<n;j++) {
                dfs(i, j);
                if(tmp_area>max_area)
                {
                    max_area=tmp_area;
                    max_length=tmp_length;
                }
                tmp_area=0;
                tmp_length=0;
            }
    }
    return 0;
}
