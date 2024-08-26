#include <stdio.h>
#define ll long long

ll n, m, l, r, k;
ll t[100005];

int main()
{
    scanf("%lld%lld", &n, &m);

    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &t[i]);
    }

    l = 0, r = 1e18;

    while (l < r)
    {
        ll mid = l + (r - l) / 2;

        k = 0;
        for (int i = 0; i < n; i++)
        {
            k += mid / t[i];
        }

        // printf("%lld %lld %lld\n", k, m, mid);

        if (k < m)
        {
            l = mid + 1;
        }
        else
            r = mid;
    }

    printf("%lld", r);

    return 0;
}