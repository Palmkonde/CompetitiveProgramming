#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int N = 10005;
const int M = 100005;

int n, m, s, t, b;
int dist[2][N];
bool visited[2][N];
vector<pii> adj[M];
priority_queue<pii, vector<pii>, greater<pii>> pq;

void dij(int state, int source)
{
    dist[state][source] = 0;

    pq.push({0, source});
    while (not pq.empty())
    {
        int now = pq.top().second;
        int w = pq.top().first;
        pq.pop();

        if (visited[state][now])
            continue;
        visited[state][now] = true;

        for (auto e : adj[now])
        {
            int nx = e.first;
            int nw = e.second;

            if (dist[state][nx] > dist[state][now] + nw)
            {
                dist[state][nx] = dist[state][now] + nw;
                pq.push({dist[state][nx], nx});
            }
        }
    }
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> n >> m >> s >> t >> b;

    int u, v, w;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    fill_n(dist[0], N, INT_MAX);
    fill_n(dist[1], N, INT_MAX);

    dij(0, s);
    dij(1, t);

    if (dist[0][t] <= b)
    {
        cout << t << " " << dist[0][t] << " " << 0;
        return 0;
    }
    else
    {
        vector<pii> can;
        for (int i = 0; i < n; i++)
        {
            if (dist[0][i] <= b and i != s)
            {
                can.push_back({dist[1][i], i});
            }
        }

        sort(can.begin(), can.end());

        cout << can[0].second << " " << dist[0][can[0].second] << " " << can[0].first;
    }

    return 0;
}