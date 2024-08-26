#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int N = 100005;

int n, k, q, x;
bool vis[N];
int e[N], dist[N];
priority_queue<pii, vector<pii>, greater<pii>> pq;
vector<int> adj[N];

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> n >> k >> q >> x;

    for (int i = 1; i <= n; i++)
    {
        cin >> e[i];
    }

    int a, b;
    for (int i = 0; i < k; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
    }

    fill(dist, dist + n + 1, INT_MAX);
    dist[x] = e[x];
    pq.push({dist[x], x});

    while (not pq.empty())
    {
        int now = pq.top().second;
        pq.pop();

        if (vis[now])
            continue;
        vis[now] = true;

        for (auto child : adj[now])
        {
            int nx = child;

            if (dist[nx] > dist[now] + e[nx])
            {
                dist[nx] = dist[now] + e[nx];
                pq.push({dist[nx], nx});
            }
        }
    }

    while (q--)
    {
        cin >> a;
        cout << dist[a] << "\n";
    }

    return 0;
}