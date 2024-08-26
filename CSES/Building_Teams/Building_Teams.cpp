#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, m;
bool vis[N];
char color[N];
vector<int> adj[N];

void dfs(int x, int c)
{
    vis[x] = true;

    if (color[x] == -1)
    {
        color[x] = c;
    }

    for (auto e : adj[x])
    {
        if (vis[e])
        {
            if (color[e] != -1 and color[x] == color[e])
            {
                printf("IMPOSSIBLE");
                exit(0);
            }
            continue;
        }

        dfs(e, !c);
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

    memset(color, -1, sizeof(color));
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            continue;

        dfs(i, 0);
    }

    for (int i = 1; i <= n; i++)
    {
        printf("%d ", color[i] + 1);
    }
    return 0;
}