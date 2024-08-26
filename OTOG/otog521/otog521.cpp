#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using tii = tuple<ll, ll, ll, ll>;
using pii = pair<int, int>;

const int N = 80005;

ll n, m, l, q;
ll dist[N][10];
bool pos[N];
vector<pii> adj[N];
priority_queue<tii, vector<tii>, greater<tii>> pq;

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> n >> m >> l >> q;

    ll u, v, w;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    for (int i = 0; i < l; i++)
    {
        cin >> u;
        pos[u] = true;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= q; j++)
        {
            dist[i][j] = LLONG_MAX - 1;
        }
    }

    dist[1][0] = 0;
    pq.push({0, 0, 1, 0});

    while (not pq.empty())
    {
        ll now, k, tmp, last;
        tie(tmp, k, now, last) = pq.top();
        pq.pop();

        if (now == n)
        {
            cout << tmp;
            return 0;
        }

        if (pos[now] and k < q and now != last)
        {
            pq.push({tmp, k + 1, now, now});
        }

        for (auto e : adj[now])
        {
            ll nx = e.first;
            ll nw = e.second;

            if (dist[nx][k] > tmp + (nw >> k))
            {
                dist[nx][k] = tmp + (nw >> k);
                pq.push({dist[nx][k], k, nx, last});
            }
        }
    }

    return 0;
}