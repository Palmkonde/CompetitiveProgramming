#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int N = 2005;

int n, m, s, t, u, v, w;
vector<pii> adj[N];
priority_queue<pii, vector<pii>, greater<pii>> pq;
int64_t dist[N];
bool vis[N];

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> n >> s >> t >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back({v, w + ((u == s) ? 0 : 20)});
    }

    fill_n(dist, N, INT64_MAX);
    dist[s] = 0;
    pq.push({0, s});

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
            int w = e.second;

            if (dist[nx] > dist[now] + w)
            {
                dist[nx] = dist[now] + w;
                pq.push({dist[nx], nx});
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << dist[i] << " ";
    }

    cout << "\n"
         << dist[t];

    return 0;
}

/*
8 0 7 14
0 1 10
0 3 14
0 4 8
1 2 2
2 7 2
2 3 4
3 7 15
3 4 9
5 3 7
5 7 2
4 5 5
4 6 1
6 5 1
6 4 3

4
0 10 2 30
*/

/*
lock 8 10 14

0 10 12 14 8 10 09 12  h = 0
0 10 14 14 8 14 11 18 h = 2
0 10 22 14 8 23 19 34 h = 10
0 10 32 14 8 33 29 49 h = 20
*/