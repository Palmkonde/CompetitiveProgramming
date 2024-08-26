#include <bits/stdc++.h>
using namespace std;

int n;
int dp[1005][1005];
char card[1005];

int mcm(int l, int r)
{
    if (l >= r)
        return 0;

    if (dp[l][r] != -1)
        return dp[l][r];

    if (card[l] == card[r])
    {
        dp[l][r] = max(dp[l][r], 1 + mcm(l + 1, r - 1));
    }

    for (int i = l; i <= r; i++)
    {
        dp[l][r] = max(dp[l][r], mcm(l, i) + mcm(i + 1, r));
    }

    return dp[l][r];
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> card[i];
    }

    memset(dp, -1, sizeof(dp));

    cout << mcm(1, n);

    return 0;
}