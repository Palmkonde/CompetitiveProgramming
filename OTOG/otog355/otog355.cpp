#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1005;

ll n, k;
ll a[N];

ll recur(int now, int pop)
{
    if (now > n)
        return 0;

    ll res = 1e9;

    if (pop > 0)
    {
        res = min(res, recur(now + 1, pop - 1));
    }

    res = min(res, recur(now + 1, pop) + a[now]);

    return res;
}

int main()
{
    scanf("%lld%lld", &n, &k);

    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
    }

    printf("%lld", recur(1, k));

    return 0;
}