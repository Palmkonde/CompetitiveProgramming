#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;

ll q, x;

int main()
{
    scanf("%lld", &q);

    while (q--)
    {
        scanf("%lld", &x);

        if (x == 1 or x == 2)
        {
            printf("NO\n");
            continue;
        }

        else
        {
            ll ans = (x - 3);
            printf("%lld\n", ans % MOD);
        }
    }

    return 0;
}