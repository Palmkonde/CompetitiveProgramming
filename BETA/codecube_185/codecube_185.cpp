#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

const int N = 1e4 + 5;

struct pqData
{
    ll w, node, tic;

    bool operator<(const pqData &other) const
    {
        if (w == other.w)
            return tic > other.tic;
        else
            return w > other.w;
    }
};

ll n, m, t;
ll st, ed;
ll dist[N][10];
bool vis[N][10];
vector<pii> adj[N];
priority_queue<pqData> pq;

int main()
{
    scanf("%lld %lld %lld", &n, &m, &t);
    scanf("%lld %lld", &st, &ed);

    ll u, v, w;
    for (int i = 0; i < m; i++)
    {
        scanf("%lld %lld %lld", &u, &v, &w);
        adj[u].push_back({v, w});
    }

    fill_n(dist[0], N * 10, LLONG_MAX);
    dist[st][1] = 0;
    pq.push({0, st, 1});

    while (not pq.empty())
    {
        pqData now = pq.top();
        pq.pop();

        // if(vis[now.node][now.tic]);
        // vis[now.node][now.tic] = true;

        // printf("%lld:",now.node);
        for (auto e : adj[now.node])
        {
            ll nx = e.first;
            ll nw = e.second;
            ll nt = (now.tic+1)%t;

            if (dist[nx][nt] > dist[now.node][now.tic] + nw)
            {
                // printf("%lld ",dist[now.node][now.tic]);
                dist[nx][nt] = dist[now.node][now.tic] + nw;
                pq.push({dist[nx][nt], nx, nt});
            }
        }
        // printf("\n");
    }
    printf("%lld", (dist[ed][0] == LLONG_MAX) ? -1 : dist[ed][0]);
    return 0;
}