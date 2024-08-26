#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
const int MOD = 1e9 + 7;

int64_t dp[N][N];
char buff[N];
char mp[N][N];
int n;

int64_t recur(int x, int y)
{
    int64_t res = 0;

    if (x >= n or y >= n or x < 0 or y < 0)
        return 0;

    if (mp[x][y] == '*')
        return 0;

    if (dp[x][y] != -1)
        return dp[x][y];

    if (x == n - 1 and y == n - 1)
        return 1;

    res += (mp[x + 1][y] == '*') ? 0 : recur(x + 1, y);
    res += (mp[x][y + 1] == '*') ? 0 : recur(x, y + 1);

    return dp[x][y] = res % MOD;
}

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf(" %s", buff);
        for (int j = 0; j < n; j++)
        {
            mp[i][j] = buff[j];
        }
    }

    memset(dp, -1, sizeof(dp));
    printf("%lld", recur(0, 0));

    return 0;
}