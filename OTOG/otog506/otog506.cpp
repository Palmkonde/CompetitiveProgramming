#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int t;
int64_t x, y, z, f1, f2, f3, n;

int main()
{
    scanf("%d", &t);

    while (t--)
    {
        scanf("%d %d %d %d %d %d %d", &x, &y, &z, &f1, &f2, &f3, &n);

        if (n <= 2)
        {
            if (n == 0)
                printf("%lld", f1);
            else if (n == 1)
                printf("%lld", f2);
            else if (n == 2)
                printf("%lld", f3);

            printf("\n");
            continue;
        }

        int64_t res = 0;
        for (int i = 3; i <= n; i++)
        {
            res = x * f3 + y * f2 + z * f1;
            f1 = f2;
            f2 = f3;
            f3 = res % MOD;
        }

        printf("%lld\n", f3);
    }

    return 0;
}