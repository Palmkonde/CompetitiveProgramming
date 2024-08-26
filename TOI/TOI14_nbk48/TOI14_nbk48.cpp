#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

const int N = 1e5 + 5;

ll n, q;
ll a[N];
pll qs[N];

int up(ll k)
{
    int l = 1, r = n + 1, mid;
    while (l < r)
    {
        mid = l + (r - l) / 2;

        if (qs[mid].first <= k)
        {
            l = mid + 1;
        }
        else
            r = mid;
    }
    return qs[r - 1].second;
}

int main()
{
    scanf("%lld%lld", &n, &q);

    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
    }

    for (int i = 1; i <= n; i++)
    {
        qs[i].first = qs[i - 1].first + a[i];
        qs[i].second = i;
    }

    sort(qs + 1, qs + n + 1, [](const pll &a, const pll &b)
         {
        if(a.first == b.first)
        {
            return a.second < b.second;
        }
        return a.first < b.first; });

    for (int i = 1; i <= n; i++)
    {
        qs[i].second = max(qs[i].second, qs[i - 1].second);
    }

    ll k;
    while (q--)
    {
        scanf("%lld", &k);
        int idx = up(k);

        printf("%d\n", idx);
    }

    return 0;
}