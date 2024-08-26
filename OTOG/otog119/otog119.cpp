#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int N = 10005;

int dist[N];
int dist2[N];
int vis[N];
vector<pii> adj[N];
priority_queue<pii, vector<pii>, greater<pii>> pq;
int u, v, w, s, t, n, m;

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> n >> m >> s >> t;

    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    fill_n(dist, N, INT_MAX);
    fill_n(dist2, N, INT_MAX);

    pq.push({0, s});

    while (not pq.empty())
    {
        int now = pq.top().second;
        int w = pq.top().first;
        pq.pop();

        if (dist2[now] < w)
            continue;

        for (auto e : adj[now])
        {
            int nw = e.second + w;

            if (dist[e.first] > nw)
            {
                dist2[e.first] = dist[e.first];
                dist[e.first] = nw;
                pq.push({nw, e.first});
            }
            else if (nw > dist[e.first] and nw < dist2[e.first])
            {
                dist2[e.first] = nw;
                pq.push({nw, e.first});
            }
        }
    }

    cout << dist2[t];

    return 0;
}

/*
https://medium.com/javarevisited/solve-the-second-shortest-path-problem-7c1082e85049
*/
