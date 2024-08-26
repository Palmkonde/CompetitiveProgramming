#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, a, b, c;

ll po(ll h, int e)
{
    ll res = 1;
    for (int i = 1; i <= e; i++)
    {
        res *= h;
    }
    return res;
}

int main()
{
    scanf("%lld%lld%lld", &a, &b, &c);

    ll ta, tb, tc;
    for (int i = 1; i <= 3; i++)
    {
        ta = po(a, i);
        tb = po(b, i);
        tc = po(c, i);

        // printf("%lld %lld %lld\n", ta, tb, tc);

        if ((ta + tb) == tc)
        {
            printf("%d", i);
            return 0;
        }
    }

    printf("NO");

    return 0;
}