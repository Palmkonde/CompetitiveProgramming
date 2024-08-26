#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
using ll = long long;
using pli = pair<ll, int>;

const int N = 505;
const int M = 2005;

int n, m;
vector<pii> adj[N];
tiii edge[M];
priority_queue<pli, vector<pli>, greater<pli>> pq;

ll dijstra(int u, int v)
{
    bool vis[N];

    vector<ll> dist(N, INT_MAX);
    memset(vis, 0, sizeof(vis));

    dist[u] = 0;
    pq.push({dist[u], u});

    while (not pq.empty())
    {
        int now = pq.top().second;
        pq.pop();

        if (vis[now])
            continue;
        vis[now] = true;

        for (auto e : adj[now])
        {
            int nx = e.first;
            int nw = e.second;

            if (dist[nx] > dist[now] + nw)
            {
                dist[nx] = dist[now] + nw;
                pq.push({dist[nx], nx});
            }
        }
    }

    return dist[v];
}

int main()
{
    scanf("%d%d", &n, &m);

    int u, v, w;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &u, &v, &w);

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        edge[i] = make_tuple(u, v, w);
    }

    ll mn = INT_MAX;
    for (int i = 0; i < m; i++)
    {
        tie(u, v, w) = edge[i];

        // printf("->%d %d %d\n", u, v, w);

        for (int i = 0; i < adj[u].size(); i++)
        {
            if (adj[u][i] == make_pair(v, w))
            {
                adj[u].erase(adj[u].begin() + i);
            }
        }

        for (int i = 0; i < adj[v].size(); i++)
        {
            if (adj[v][i] == make_pair(u, w))
            {
                adj[v].erase(adj[v].begin() + i);
            }
        }

        ll d = dijstra(u, v);

        mn = min(mn, d + w);

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    printf("%lld", mn);

    return 0;
}