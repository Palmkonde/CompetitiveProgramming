#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

const int N = 60;

int n,a,b;
int mp[N][N];
pii st,ed,wit;
int dist[N][N][2];
bool visited[N][N][2];
int dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0};

struct dat
{
    int x,y;
    int dis;
    int swt;
};

struct cmp
{
    bool operator() (const dat &a, const dat &b)
    {
        return a.dis > b.dis;
    }  
};

priority_queue<dat, vector<dat>, cmp> pq;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;++j)
        {
            cin >> mp[i][j];
        }
    }
    cin >> a >> b;
    st = {a,b};
    cin >> a >> b;
    ed = {a,b};

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=0;k<2;k++)
            {
                dist[i][j][k] = INT_MAX;
            }
        }
    }

    pq.push({st.first,st.second,0,0});
    dist[st.first][st.second][0] = 0;

    while(!pq.empty())
    {
        dat now = pq.top();pq.pop();

        if(visited[now.x][now.y][now.swt]) continue;
        visited[now.x][now.y][now.swt] = true;

        for(int i=0;i<4;i++)
        {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if(nx < 1 or ny < 1 or nx > n or ny > n) continue;

            if(mp[nx][ny] > 0)
            {
                if(dist[now.x][now.y][now.swt]+mp[nx][ny] < dist[nx][ny][now.swt])
                {
                    dist[nx][ny][now.swt] = dist[now.x][now.y][now.swt] + mp[nx][ny];
                    pq.push({nx,ny,dist[nx][ny][now.swt],now.swt});
                }
            }
            else
            {
               if(dist[now.x][now.y][now.swt] + abs(mp[nx][ny]) < dist[nx][ny][now.swt^1])
                {
                    dist[nx][ny][now.swt^1] = dist[now.x][now.y][now.swt] + abs(mp[nx][ny]);
                    pq.push({nx,ny,dist[nx][ny][now.swt^1],now.swt^1});
                } 
            }
        }
    }

    cout << dist[ed.first][ed.second][1];

    return 0;
}