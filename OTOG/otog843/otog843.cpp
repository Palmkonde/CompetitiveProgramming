#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, m, cnt, timer;
int low[N], in[N];
vector<int> adj[N];

void tarjan(int u, int p)
{
    in[u] = low[u] = ++timer;

    for (auto e : adj[u])
    {
        if (e == p)
            continue;

        if (!in[e])
        {
            tarjan(e, u);
            low[u] = min(low[u], low[e]);
            cnt += (low[e] > in[u]);
        }

        else
            low[u] = min(low[u], low[e]);
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

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {

        if (!in[i])
        {
            cnt = 0;
            tarjan(i, -1);
            ans += cnt + 1;
        }
    }

    printf("%d", ans);

    return 0;
}