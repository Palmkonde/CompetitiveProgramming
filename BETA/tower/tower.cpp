#include <bits/stdc++.h>
using namespace std;

const int N = 10005;

vector<int> adj[N];
int k, n, m;
bool visited[N];

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> k >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    queue<pair<int, int>> q;
    q.push({1, 0});

    int ans = -99;
    while (not q.empty())
    {
        int now = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (visited[now])
            continue;
        visited[now] = true;

        if (cnt > k)
            break;

        for (auto e : adj[now])
        {
            q.push({e, cnt + 1});
        }

        ans = max(ans, now);
    }

    cout << ans;

    return 0;
}