#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int N = 100006;

int n, a, b, w;
int dist[N];
bool v[N];
vector<pii> adj[N];
priority_queue<pii, vector<pii>, greater<pii>> pq;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++)
    {
        scanf("%d%d%d", &a, &b, &w);

        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    fill(dist, dist + N + 1, INT_MAX);

    dist[1] = 0;
    pq.push({dist[1], 1});

    while (not pq.empty())
    {
        int now = pq.top().second;
        pq.pop();

        if (v[now])
            continue;

        v[now] = true;

        for (auto e : adj[now])
        {
            int nx = e.first;
            int nw = e.second;

            if (v[nx])
                continue;

            if (dist[nx] > dist[now] + nw)
            {
                dist[nx] = dist[now] + nw;
                pq.push({dist[nx], nx});
            }
        }
    }

    int mx = *max_element(dist + 1, dist + 1 + n);

    printf("%d", mx);

    return 0;
}