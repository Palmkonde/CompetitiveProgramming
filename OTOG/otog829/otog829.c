#include <stdio.h>
#include <stdlib.h>
#define ll long long int

ll n, q;
ll arr[100005], qs[100005];

int lw(int l, int r, ll target)
{
    while (l < r)
    {
        int mid = l + (r - l) / 2;

        if (qs[mid] < target)
        {
            l = mid + 1;
        }

        else
        {
            r = mid;
        }
    }

    return r;
}

int main()
{
    scanf("%lld%lld", &n, &q);

    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &arr[i]);
    }

    for (int i = 1; i <= n; i++)
    {
        qs[i] = arr[i - 1] + arr[i] + arr[i + 1];
    }

    ll k;
    while (q--)
    {
        scanf("%lld", &k);

        int idx = lw(0, n, k);

        printf("%d\n", idx);
    }

    return 0;
}