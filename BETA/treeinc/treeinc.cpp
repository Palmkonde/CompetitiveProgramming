#include <bits/stdc++.h>
using namespace std;

const int N = 300005;

int n;
vector<int> adj[N];
int dp[N];

int dfs(int x, int p)
{
    if (dp[x])
        return dp[x];

    int sum = 0;
    for (auto nx : adj[x])
    {

        if (nx == p)
            continue;

        if (x < nx)
        {
            sum = max(sum, dfs(nx, x) + 1);
        }
    }

    return dp[x] = sum;
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

    int mx = -1;
    for (int i = 1; i <= n; i++)
    {
        mx = max(dfs(i, -1) + 1, mx);
    }

    printf("%d", mx);

    return 0;
}