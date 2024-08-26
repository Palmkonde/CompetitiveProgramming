#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, k, rep[N];
bool vis[N];
vector<int> adj[N];

void dfs(int x)
{

    vis[x] = true;
    for (auto e : adj[x])
    {
        if (vis[e])
            continue;

        dfs(e);
    }
}

int count_com()
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            continue;

        rep[cnt++] = i;
        dfs(i);
    }

    return cnt;
}

int main()
{
    scanf("%d %d", &n, &k);

    int u, v;
    for (int i = 0; i < k; i++)
    {
        scanf("%d%d", &u, &v);

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = count_com(); // ดูว่ามีกี่กราฟที่ยังไม่เชื่อมกัน
    printf("%d\n", ans - 1);
    for (int i = 1; i < ans; i++)
    {
        printf("%d %d\n", rep[i - 1], rep[i]); // ให้ head ของแต่ละ compoundnent เชื่อมกัน
    }

    return 0;
}