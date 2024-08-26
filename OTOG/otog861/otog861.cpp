#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 50005;

ll n, q;
ll a[N], b[N];

int main()
{
    scanf("%lld%lld", &n, &q);

    ll tmp;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &tmp);
        a[i] = a[i - 1] + tmp;
    }

    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &tmp);
        b[i] = b[i - 1] + tmp;
    }

    for (int i = 1; i <= n; i++)
    {
        if (a[i - 1] > a[i])
        {
            a[i] = a[i - 1];
        }

        if (b[i - 1] > b[i])
        {
            b[i] = b[i - 1];
        }
    }

    while (q--)
    {
        scanf("%lld", &tmp);

        int l = 1, r = n;
        while (l < r)
        {
            int mid = l + (r - l) / 2;

            ll con = a[mid] + b[mid];

            // printf("%d %d\n", con, mid);

            if (con < tmp)
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }

        printf("%d\n", r);
    }

    return 0;
}