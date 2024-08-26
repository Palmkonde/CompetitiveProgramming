#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int child[N];
int n, a;
vector<int> adj[N];

void dfs(int x)
{
    child[x] = 1;

    for (auto e : adj[x])
    {
        dfs(e);
        child[x] += child[e];
    }
}

int main()
{
    scanf("%d", &n);

    for (int i = 1; i < n; i++)
    {
        scanf("%d", &a);
        a--;

        adj[a].push_back(i);
    }

    dfs(0);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", child[i] - 1);
    }

    return 0;
}