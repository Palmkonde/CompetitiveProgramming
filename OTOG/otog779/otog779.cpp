#include <bits/stdc++.h>
using namespace std;
using ll = long long;

priority_queue<ll, vector<ll>, greater<ll>> pq;
int n, k;

int main()
{
    scanf("%d%d", &n, &k);

    ll tmp;
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &tmp);
        pq.push(tmp);
    }

    ll ans = 0;

    while (k--)
    {
        ll now = pq.top();
        pq.pop();

        // printf("%lld\n", now);
        ans += now;

        pq.push(now * 1.05);
    }

    printf("%lld", ans);

    return 0;
}