#include <stdio.h>
#define min(a, b) (a < b) ? a : b
int n, m;
int c[25], dp[10005];

int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++)
        scanf("%d", &c[i]);

    for (int i = 0; i <= m; i++)
        dp[i] = 100000;

    dp[0] = 0;
    for (int i = 0; i <= m; i++)
    {
        for (int w = 0; w < n; w++)
        {
            if (i - c[w] >= 0)
            {
                dp[i] = min(dp[i], dp[i - c[w]] + 1);
            }
        }
    }

    printf("%d", dp[m]);

    return 0;
}