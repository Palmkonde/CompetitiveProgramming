#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

const int N = 50005;

struct pqData
{
    int w,node,state;
    
    bool operator<(const pqData &other) const
    {
        if(this->w == other.w) return this->state > other.state;
        return this->w > other.w;
    }
};


int n,m,l,s,t;
int dist[N][35], p[N];
bool vis[N][35];
vector<pii> adj[N];
priority_queue<pqData> pq;

int main()
{
    scanf("%d %d %d",&n,&m,&l);
    scanf("%d %d",&s,&t);

    fill_n(dist[0], N*35, INT_MAX);

    int tmp;
    for(int i=1;i<=n;i++) scanf("%d", &p[i]);
 
    int u,v,w;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        adj[u].push_back({v,w});
    }

    dist[1][0] = 0;
    pq.push({dist[1][0], 1, 0});

    while(not pq.empty())
    {
        pqData now = pq.top();
        pq.pop();

        if(vis[now.node][now.state]) continue;
        vis[now.node][now.state] = true;

        if(now.node == t and now.state == l) break;

        for(auto e:adj[now.node])
        {
            int nx = e.first;
            int nw = e.second;

            if(p[nx] == now.state + 1)
            {    
                if(dist[nx][now.state+1] > dist[now.node][now.state] + nw)
                {
                    dist[nx][now.state+1] = dist[now.node][now.state] + nw;
                    pq.push({dist[nx][now.state+1], nx, now.state+1});
                }             
            }

            if(dist[nx][now.state] > dist[now.node][now.state] + nw)
            {
                dist[nx][now.state] = dist[now.node][now.state] + nw;
                pq.push({dist[nx][now.state], nx, now.state});
            }

        }
    }
    
    printf("%d",((dist[t][l] == INT_MAX) ? -1 : dist[t][l]));

    return 0;
}