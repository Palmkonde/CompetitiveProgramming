#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int M = 105;
const int MOD = 1e9 + 7;

int n, m;
int dp[N][M], arr[N];

int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }

    if (!arr[1])
    {
        for (int i = 1; i <= m; i++)
            dp[1][i] = 1;
    }
    else
    {
        dp[1][arr[1]] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        if (arr[i])
        {
            for (int k = -1; k <= 1; k++)
            {
                dp[i][arr[i]] += dp[i - 1][arr[i] - k];
                dp[i][arr[i]] %= MOD;
            }
            continue;
        }

        for (int j = 1; j <= m; j++)
        {

            for (int k = -1; k <= 1; k++)
            {
                dp[i][j] += dp[i - 1][j + k];
                dp[i][j] %= MOD;
            }
        }
    }

    if (arr[n])
        printf("%d", dp[n][arr[n]]);
    else
    {
        int res = 0;
        for (int i = 1; i <= m; i++)
        {
            res += dp[n][i];
            res %= MOD;
        }
        printf("%d", res);
    }

    return 0;
}
