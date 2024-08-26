#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, k;
vector<int> adj[N];
int color[N], parent[N];

void dfs(int x, int r)
{
    if (color[x] != 0)
        return;
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> n >> k;

    int u, v;
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(k, 1);

    return 0;
}

/*
4 3
3 2
3 1
1 4
*/