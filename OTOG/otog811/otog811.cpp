#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

const int N = 100002;

int n,m,s,t;
vector<pii> adj[N];
int dist[N];
int parent[N];
int cnt = 0;
priority_queue<pii, vector<pii>, greater<pii>> pq;

void printPath(int x)
{
    if(parent[x] == -1)
    {
        printf("%d ",x);
        cnt++;
        return;
    }
    printPath(parent[x]);
    cnt++;
    printf("%d ", x);
}

void c(int x)
{
    if(parent[x] == -1)
    {
        cnt++;
        return;
    }
    c(parent[x]);
    cnt++;
    
}

int main()
{
    scanf("%d %d %d %d", &n, &m , &s, &t);

    for(int i=0;i<m;i++)
    {
        int u,v,w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    fill(dist,dist+n,INT_MAX);
    memset(parent,-1,sizeof(parent));

    dist[s] = 0;
    pq.push({0,s});

    while(not pq.empty())
    {
        int now = pq.top().second;
        int temp = pq.top().first;
        pq.pop();

        for(auto e:adj[now])
        {
            int nx = e.first;
            if(temp + e.second < dist[nx])
            {
                dist[nx] = temp + e.second;
                parent[nx] = now;
                pq.push({dist[nx],nx});
            }
        }
    }

    printf("%d\n", dist[t]);
    c(t);
    printf("%d\n", cnt);
    printPath(t);

    return 0;
}