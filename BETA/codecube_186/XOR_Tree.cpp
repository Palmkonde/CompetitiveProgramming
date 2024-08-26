#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int N = 100005;
vector<pii> adj[N];
bool vis[N];
int dist[N];
int n, m;

void dfs(int x)
{
    for (auto e : adj[x])
    {
        if (vis[e.first])
            continue;

        vis[e.first] = true;
        dist[e.first] = (dist[x] ^ e.second);
        dfs(e.first);
    }
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> n >> m;

    int u, v, w;
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vis[1] = 1;
    dfs(1);

    int a, b;
    while (m--)
    {
        cin >> a >> b;
        cout << (dist[a] ^ dist[b]) << "\n";
    }
    return 0;
}