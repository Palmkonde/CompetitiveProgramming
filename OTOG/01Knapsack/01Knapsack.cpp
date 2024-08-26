#include <bits/stdc++.h>
using namespace std;

int n, m;
int p[105], w[105], dp[105][10005];

int recur(int now, int bp)
{
    int res;
    if (now < 0 or bp == 0)
        return 0;

    if (dp[now][bp])
        return dp[now][bp];

    if (bp < w[now])
        return recur(now - 1, bp);

    res = max(recur(now - 1, bp - w[now]) + p[now], recur(now - 1, bp));

    return dp[now][bp] = res;
}

int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &w[i], &p[i]);
    }

    // topdown
    // printf("%d\n", recur(n - 1, m));

    // bt
    for (int i = 1; i <= n; i++) // ของชิ้นที่ i
    {
        for (int j = 0; j <= m; j++) // น้ำหนักของกระเป๋าเราที่ j
        {
            if (j < w[i]) // ของหนักกว่ากระเป๋า
                dp[i][j] = dp[i - 1][j];

            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + p[i]);
            }
        }
    }

    printf("%d", dp[n][m]);

    return 0;
}