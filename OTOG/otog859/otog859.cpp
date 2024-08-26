#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using tiii = tuple<ll, ll, ll>;

const int N = 100005;

ll n, m, k;
ll parent[N], h[N];
priority_queue<tiii> pq;

ll root(ll x)
{
    if (parent[x] == -1)
    {
        return x;
    }
    else
        return parent[x] = root(parent[x]);
}

int main()
{
    scanf("%lld %lld %lld", &n, &m, &k);

    memset(parent, -1, sizeof(parent));
    fill(h, h + n + 1, 1);

    ll a, b, w;
    for (int i = 0; i < m; i++)
    {
        scanf("%lld %lld %lld", &a, &b, &w);
        pq.emplace(w, a, b);
    }

    ll com = n - k;

    ll mx = INT_MAX;
    while (not pq.empty() and com != 0)
    {
        tie(w, a, b) = pq.top();
        pq.pop();

        ll pa = root(a);
        ll pb = root(b);

        if (pa != pb)
        {
            if (h[pa] < h[pb])
                swap(pa, pb);

            h[pa] += h[pb];
            parent[pb] = pa;
            com--;

            mx = min(mx, w);
        }
    }

    printf("%lld", mx);

    return 0;
}