#include <bits/stdc++.h>
using namespace std;

int n;
int dp[105];

int main()
{
    scanf("%d", &n);

    dp[0] = 1;
    for (int m = 0; m <= n; m++)
    {
        for (int k = 1; k <= n; k++)
        {
            if (m - k >= 0)
            {
                dp[m] += dp[m - k];
            }
        }
    }

    printf("%d", dp[n]);

    return 0;
}