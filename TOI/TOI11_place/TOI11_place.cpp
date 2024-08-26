#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using TUPLE = tuple<int,int,int>;

const int MAXN = 200002;

int n,m;
priority_queue<pii> pq;
vector<pii> adj[MAXN];
int inMst[MAXN];
int dist[MAXN];
long long ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    fill(dist,dist+(n + 2), INT_MIN);

    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        w--;

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    pq.push({0,1});
    dist[1] = 0;
    while(not pq.empty())
    {
        int now = pq.top().second;
        pq.pop();

        if(inMst[now]) continue;
        inMst[now] = true;

        ans += dist[now];
        for(auto e:adj[now])
        {
            int next = e.first;
            int w = e.second;

            if(!inMst[next] and (w > dist[next]))
            {
                dist[next] = w;
                pq.push({w,next});
            }
        }

    }

    cout << ans;

    return 0;
}