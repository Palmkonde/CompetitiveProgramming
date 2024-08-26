#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int N = 50005;

struct pqData
{
    int64_t w;
    int node;
    int toggle;
};

struct cmp
{
    bool operator()(const pqData &a, pqData &b)
    {
        return a.w > b.w;
    }
};

int n, m;
int st = 0;
vector<pii> adj[N];
string code;
map<char, int> shifting = {
    {'S', 0},
    {'A', 1},
    {'M', 2},
    {'X', 3}};
char h[N];
int64_t dist[N][20];
bool visited[N][20];

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> n >> m;
    cin >> code;

    for (int i = 2; i <= n; i++)
    {
        cin >> h[i];
    }

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    for (int i = 0; i < 4; i++)
    {
        if (code[i] == '_')
            continue;

        else
        {
            st = st | (1 << shifting[code[i]]);
        }
    }

    priority_queue<pqData, vector<pqData>, cmp> pq; // w, node, toggle

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            dist[i][j] = INT64_MAX;
        }
    }

    dist[n][st] = 0;
    pq.push({0, n, st});

    while (not pq.empty())
    {
        pqData now = pq.top();
        pq.pop();

        if (visited[now.node][now.toggle])
            continue;
        visited[now.node][now.toggle] = true;

        int newtog = now.toggle;
        if (h[now.node] == 'X' or h[now.node] == 'M' or h[now.node] == 'A' or h[now.node] == 'S')
        {
            newtog |= (1 << shifting[h[now.node]]);
        }

        for (auto e : adj[now.node])
        {
            int nx = e.first;
            int w = e.second;

            if (dist[nx][newtog] > dist[now.node][now.toggle] + w)
            {
                dist[nx][newtog] = dist[now.node][now.toggle] + w;
                pq.push({dist[nx][newtog], nx, newtog});
            }
        }
    }

    cout << dist[1][15];

    return 0;
}