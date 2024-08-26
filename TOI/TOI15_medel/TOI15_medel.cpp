#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 500005;

ll n;
ll arr[N], h[N], ans[N];

int main()
{
    scanf("%lld", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &h[i]);
    }

    sort(h, h + n);
    sort(arr, arr + n, greater<ll>());

    for (int i = 0; i < n; i++)
    {
        ans[i] = arr[i] + h[i];
    }

    sort(ans, ans + n);

    printf("%lld", ans[n - 1] - ans[0]);

    return 0;
}