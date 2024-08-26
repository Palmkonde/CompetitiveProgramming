#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using TUPLE = tuple<int, int, int>;

const int N = 40005;

int n, m, q, l;
int u, v, w, p;
int64_t dist[N][15];
int potion[N];
vector<pii> adj[N];
priority_queue<TUPLE, vector<TUPLE>, greater<TUPLE>> pq; // dist node stack_potion

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> n >> m >> l >> q;

    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    for (int i = 0; i < l; i++)
    {
        cin >> p;
        potion[p]++;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            dist[i][j] = INT64_MAX;
        }
    }

    dist[1][0] = 0;
    pq.push({0, 1, 0});

    while (not pq.empty())
    {
        int64_t ww;
        int now, cnt;
        tie(ww, now, cnt) = pq.top();
        pq.pop();

        if (cnt < q)
        {
            if (potion[now] != 0)
            {
                potion[now]--;
                cnt++;
            }
        }

        for (auto e : adj[now])
        {
            int64_t nw = ww + (e.second / (1 << cnt));
            int nx = e.first;

            if (dist[nx][cnt] > nw)
            {
                dist[nx][cnt] = nw;
                pq.push({nw, nx, cnt});
            }
        }
    }

    int64_t mn = INT64_MAX;
    for (int i = 0; i <= q; i++)
    {
        if (mn > dist[n][i])
        {
            mn = dist[n][i];
        }
    }

    cout << mn;

    return 0;
}
