#include <bits/stdc++.h>
using namespace std;

int q;
int64_t dp[60], a;

int64_t recur(int64_t x)
{
    if (dp[x])
        return dp[x];

    if (x == 1)
    {
        return 69;
    }

    if (!(x & 1))
    {
        return dp[x] = recur(x - 1) + x;
    }
    else
    {
        return dp[x] = recur(x - 1) + recur(x - 2) + x;
    }
}

int main()
{
    scanf("%d", &q);

    dp[1] = 69;
    while (q--)
    {
        scanf("%lld", &a);
        printf("%lld\n", recur(a));
    }
    return 0;
}