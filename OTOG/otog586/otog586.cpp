#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;

int n;
int cnt[N];
vector<int> adj[N];

void dfs(int u, int p)
{
    cnt[u] = 1;
    for (auto e : adj[u])
    {
        if (e == p)
            continue;

        dfs(e, u);
        cnt[u] += cnt[e];
    }
}

int main()
{
    scanf("%d", &n);

    int u, v;
    for (int i = 1; i < n; i++)
    {
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0, -1);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", cnt[i]);
    }

    return 0;
}