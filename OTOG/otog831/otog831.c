#include <stdio.h>
#include <stdlib.h>
#define ll long long

ll dp[60];
int q, a;

ll recur(int num)
{
    if (dp[num] != 0)
        return dp[num];

    return dp[num] = (!(num & 1)) ? recur(num - 1) + num : recur(num - 1) + recur(num - 2) + num;
}

int main()
{
    dp[1] = 69;

    scanf("%d", &q);

    while (q--)
    {
        scanf("%d", &a);
        printf("%lld\n", recur(a));
    }

    return 0;
}