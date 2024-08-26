#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

const int N = 10005;
const int M = 200005;

struct pqData
{
    int dist,node;
    bool operator<(const pqData &other) const {return this->dist > other.dist;}
};

int n,m,q,k,p,s;
int dist[N], dp[N], vis[N];
vector<pii> adj[N];
priority_queue<pqData> pq;

int main()
{
    scanf("%d %d %d %d %d %d",&n,&m,&q,&k,&p,&s);

    fill_n(&(dist[0]), N, INT_MAX);
    fill_n(&(dp[0]), N, INT_MAX);

    for(int i=0;i<m;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        adj[a].push_back({b,c});
    }
    
    dist[s] = 0;
    pq.push({dist[s],s});
    
    while(not pq.empty())
    {
        pqData now = pq.top();
        pq.pop();

        // printf("->%d\n",now.node);

        if(vis[now.node]) continue;
        vis[now.node] = 1;

        for(auto e: adj[now.node])
        {
            int nx = e.first;
            int nw = e.second;

            // printf("->%d\n",dist[now.node+nw]);

            if(dist[nx] > dist[now.node] + nw and k >= dist[now.node] + nw)
            {
                dist[nx] = dist[now.node] + nw;
                pq.push({dist[nx],nx});
            }
        }
    }

    fill_n(&(vis[0]), N, 0);
    dp[p] = 0;
    pq.push({dp[p],p});
    
    while(not pq.empty())
    {
        pqData now = pq.top();
        pq.pop();

        // printf("->%d\n",now.node);

        if(vis[now.node]) continue;
        vis[now.node] = 1;

        for(auto e: adj[now.node])
        {
            int nx = e.first;
            int nw = e.second;

            // printf("->%d\n",dist[now.node+nw]);

            if(dp[nx] > dp[now.node] + nw and k >= dp[now.node] + nw)
            {
                dp[nx] = dp[now.node] + nw;
                pq.push({dp[nx],nx});
            }
        }
    }
    
    while(q--)
    {
        int t;
        scanf("%d",&t);

        int ans = -1;

        ans = dist[t]; // ไปแบบไม่รีเซตดูก่อน
        if(dist[p] != INT_MAX) //แสดงว่าไป reset พลังได้
        {
            ans = min(ans,dp[t]);
        }

        printf("%d\n",(ans == INT_MAX) ? -1 : k-ans);
    }

    // for(int i=1;i<=n;i++) printf("%d ",dist[i]);
    // printf("\n");
    // for(int i=1;i<=n;i++) printf("%d ",dp[i]);

    return 0;
}