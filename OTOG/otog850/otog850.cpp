#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

const int N = 1005;
const int K = 105;

int n, m, u, v, w, q, c, s, e;
int p[N], dist[N][K];
vector<pii> adj[N];

void solve()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < K; j++)
        {
            dist[i][j] = INT_MAX;
        }
    }

    priority_queue<tiii, vector<tiii>, greater<tiii>> pq; // w,node,c

    scanf("%d %d %d", &c, &s, &e);

    dist[s][0] = 0;
    pq.push({dist[s][0], s, 0});

    while (not pq.empty())
    {
        int cur, now, fuel;
        tie(cur, now, fuel) = pq.top();
        pq.pop();

        // printf("%d %d %d\n", cur, now, fuel);

        if (now == e)
            break;

        if (fuel < c)
        {
            if (dist[now][fuel + 1] > cur + p[now])
            {
                dist[now][fuel + 1] = cur + p[now];
                pq.push({dist[now][fuel + 1], now, fuel + 1});
            }
        }

        for (auto child : adj[now])
        {
            int nx = child.first;
            int nw = child.second;

            if (fuel >= nw)
            {
                if (dist[nx][fuel - nw] > dist[now][fuel])
                {
                    dist[nx][fuel - nw] = dist[now][fuel];
                    pq.push({dist[nx][fuel - nw], nx, fuel - nw});
                }
            }
        }
    }

    while (not pq.empty())
        pq.pop();

    int ans = INT_MAX;

    for (int i = 0; i <= c; i++)
        ans = min(ans, dist[e][i]);

    if (ans == INT_MAX)
    {
        printf("impossible\n");
    }
    else
        printf("%d\n", ans);
}

int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++)
        scanf("%d", &p[i]);

    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    scanf("%d", &q);
    while (q--)
        solve();

    return 0;
}

/*
5 5
10 10 20 12 13
0 1 9
0 2 8
1 2 1
1 3 11
2 3 7
1
10 0 3
*/