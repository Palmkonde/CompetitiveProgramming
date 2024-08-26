#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int N = 50005;

struct pqData
{
    int w, node, state;

    bool operator<(const pqData &other) const
    {
        return this->w > other.w;
    }
};

int n, m, p, k, s, x, u, v, w;
int dist[N][25], c[N];
bool vis[N][25];
vector<pii> adj[N];
priority_queue<pqData> pq;

int main()
{
    scanf("%d %d %d %d", &n, &m, &p, &k);

    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    for (int i = 0; i < p; i++)
    {
        scanf("%d", &x);
        c[x] = 1;
    }
    scanf("%d", &s);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            dist[i][j] = INT_MAX;
        }
    }

    dist[s][0] = 0;
    pq.push({dist[s][0], s, 0});

    while (not pq.empty())
    {
        int now = pq.top().node;
        int nst = pq.top().state;
        pq.pop();

        if (vis[now][nst])
            continue;

        vis[now][nst] = 1;

        for (auto e : adj[now])
        {
            int nx = e.first;
            int nw = e.second;
            // buy
            if (nst < k and c[now])
            {
                if (dist[nx][nst + 1] > dist[now][nst] + nw)
                {
                    dist[nx][nst + 1] = dist[now][nst] + nw;
                    pq.push({dist[nx][nst + 1], nx, nst + 1});
                }
            }

            if (dist[nx][nst] > dist[now][nst] + nw)
            {
                dist[nx][nst] = dist[now][nst] + nw;
                pq.push({dist[nx][nst], nx, nst});
            }
        }
    }

    if (dist[s][k] == INT_MAX)
    {
        printf("NO FOOD :(");
    }
    else
        printf("%d", dist[s][k]);

    return 0;
}