#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, a, b, c, dis;
vector<int> adj[N];

void dfs(int x, int p, int d)
{
    for (auto child : adj[x])
    {
        if (child == p)
            continue;

        dfs(child, x, d + 1);
    }

    if (d > dis)
    {
        c = x;
        dis = d;
    }
}

int main()
{
    scanf("%d", &n);

    for (int i = 1; i < n; i++)
    {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, -1, 0);
    dis = 0;
    dfs(c, -1, 0);

    printf("%d", dis);

    return 0;
}
// CPH tree diameter algorithim 2