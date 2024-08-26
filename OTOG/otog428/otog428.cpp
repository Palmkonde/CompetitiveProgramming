#include <bits/stdc++.h>
using namespace std;

const int MOD = 100'000'003;

int n, m;
int dp[1005][1005];

int main()
{
    scanf("%d%d", &n, &m);

    dp[1][1] = 1;
    for (int i = 1; i <= n + 1; i++)
    {
        for (int j = 1; j <= m + 1; j++)
        {
            dp[i][j] += dp[i - 1][j];
            dp[i][j] += dp[i][j - 1];
            dp[i][j] %= MOD;
        }
    }

    // for (int i = 1; i <= n + 1; i++)
    // {
    //     for (int j = 1; j <= m + 1; j++)
    //     {
    //         printf("%d ", dp[i][j]);
    //     }
    //     printf("\n");
    // }

    printf("%d", dp[n + 1][m + 1]);

    return 0;
}