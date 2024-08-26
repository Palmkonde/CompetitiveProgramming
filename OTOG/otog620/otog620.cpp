#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;

int n, m, cnt;
int low[N], in[N], timer;
vector<int> adj[N];

void tarjan(int u, int p)
{
    in[u] = low[u] = ++timer;

    for (auto e : adj[u])
    {
        if (e == p)
            continue;

        if (not in[e])
        {
            tarjan(e, u);
            cnt += (low[e] > in[u]);
        }
        low[u] = min(low[e], low[u]);
    }
}

int main()
{
    scanf("%d%d", &n, &m);

    int u, v;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    tarjan(1, -1);
    printf("%d", cnt + 1);

    return 0;
}