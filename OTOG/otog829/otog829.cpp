#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int64_t n, q, k;
int64_t a[N], qs[N];

int lw(int l, int r, int64_t val)
{

    while (l < r)
    {
        int mid = l + (r - l) / 2;
        // printf("%d %d\n", l, r);
        if (qs[mid] < val)
        {
            l = mid + 1;
        }
        else
            r = mid;
    }

    return r;
}

int main()
{
    scanf("%lld %lld", &n, &q);

    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
    }

    for (int i = 1; i <= n; i++)
    {
        qs[i] = a[i - 1] + a[i] + a[i + 1];
    }

    /*
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", qs[i]);
    }
    printf("\n");
    */

    while (q--)
    {
        scanf("%lld", &k);

        int idx = lw(1, n, k);

        printf("%d\n", idx);
    }

    return 0;
}