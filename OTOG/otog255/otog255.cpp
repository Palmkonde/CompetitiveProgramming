#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, m, a, b, x, y;
int c[N];
vector<int> adj[N];

void dfs(int u, int p)
{
    for (auto e : adj[u])
    {
        if (e == p)
            continue;

        c[e] += c[u];
        dfs(e, u);
    }
}

int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 1; i < n; i++)
    {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    while (m--)
    {
        scanf("%d%d", &x, &y);
        c[x] += y;
    }

    dfs(1, -1);

    for (int i = 1; i <= n; i++)
    {
        printf("%d\n", c[i]);
    }

    return 0;
}