#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

const int N = 2002;

int m,n;
char temp[N];
char mp[N][N];
queue<pii> q;
bool visited[N][N];
int cnt;
int di[8][2] = {{0,1},{1,0},{0,-1},{-1,0},{-1,1},{1,1},{1,-1},{-1,-1}};

void bfs(int i,int j)
{
    q.push({i,j});
    while(not q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0;i<8;i++)
        {
            int nx = x + di[i][0];
            int ny = y + di[i][1];

            if(nx < 0 or ny < 0 or nx >= n or ny >= m ) continue;
            if(mp[nx][ny] == '0') continue;
            mp[nx][ny] = '0';

            q.push({nx,ny});
        }
    }
}

int main()
{
    scanf("%d %d",&n, &m);
    for(int i=0;i<n;i++)
    {
        scanf("%s",temp);
        for(int j=0;j<m;j++)
        {
            char c = temp[j];
            mp[i][j] = c;
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            
            if(mp[i][j] == '1')
            {
                bfs(i,j);
                cnt++;
            }
            
        }
    }
    
    printf("%d",cnt);

    return 0;
}