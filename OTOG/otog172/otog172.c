#include <stdio.h>
#define ll long long
#define MAX(a, b) (a > b) ? a : b

int n, m;
int arr[20][20];
ll dp[20][20];

// topdown
ll recur(int x, int y)
{
    ll res = 0;

    if (dp[x][y])
        return dp[x][y];

    if (x < 0 || y < 0 || x >= n || y >= m)
        return 0;

    res = MAX(recur(x + 1, y) + arr[x][y], recur(x, y + 1) + arr[x][y]);
    return dp[x][y] = res;
}

int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    // botton-up
    for (int x = 1; x <= n; x++)
    {
        for (int y = 1; y <= m; y++)
        {
            dp[x][y] = MAX(dp[x - 1][y] + arr[x][y], dp[x][y - 1] + arr[x][y]);
        }
    }

    printf("%lld\n", recur(1, 1));
    printf("%lld", dp[n][m]);

    return 0;
}