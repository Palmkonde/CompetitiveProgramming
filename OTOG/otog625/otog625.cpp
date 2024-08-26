#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e6 + 3;
int q, k;
int dp[100005];
int coin[] = {50, 25, 10, 5, 1};

int main()
{
    scanf("%d", &q);

    dp[0] = 1;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 1; j <= 100005; j++)
        {
            if (j - coin[i] < 0)
                continue;

            dp[j] += dp[j - coin[i]];
            dp[j] %= MOD;
        }
    }

    while (q--)
    {
        scanf("%d", &k);
        printf("%d\n", dp[k]);
    }
    return 0;
}