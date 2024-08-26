#include <bits/stdc++.h>
using namespace std;

const int N = 205;
const int MOD = 10'000'009;

char mp[N][N];
int dp[N][N][1505];
int n, m;

int recur(int i, int j, int k)
{
    int res = 0;
    if (dp[i][j][k] != -1)
        return dp[i][j][k];
    if (i >= n or j >= m)
        return 0;
    if (i == n - 1 and j == m - 1)
        return 1;
    if (k < 0)
        return 0;
    if (mp[i + 1][j] != '#')
        res = (res + recur(i + 1, j, k + ((mp[i + 1][j] == 'X') ? -1 : 0))) % MOD;
    if (mp[i][j + 1] != '#')
        res = (res + recur(i, j + 1, k + ((mp[i][j + 1] == 'X') ? -1 : 0))) % MOD;

    return dp[i][j][k] = res % MOD;
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int k;
    cin >> n >> m >> k;

    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mp[i][j];
        }
    }

    cout << recur(0, 0, k) % MOD;

    return 0;
}