#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 100005;

int n, m, u, v, w, k;
bool vis[N];
ll dist[N];
vector<pii> adj[N];
priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

int main()
{
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &u, &v, &w);

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    scanf("%d", &k);

    while (k--)
    {
        scanf("%d %d", &u, &w);
        adj[n].push_back({u, w});
    }

    fill(dist, dist + n + 1, INT_MAX);
    dist[n] = 0;
    pq.push({dist[n], n});

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

    printf("%lld", dist[0]);

    return 0;
}