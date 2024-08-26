#include <bits/stdc++.h>
using namespace std;

int n, x;
int h[1005], s[1005];
int dp[1005][100005];

int recur(int now, int mon)
{
    if (now < 1)
        return 0;
    if (mon <= 0)
        return 0;

    cout << now << " " << mon << "\n";

    int res = 0;
    res = recur(now - 1, mon);
    if (mon - h[now] >= 0)
    {
        res = max(res, recur(now - 1, mon - h[now]) + s[now]);
    }

    return res;
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> n >> x;

    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }

    // dp[i][j] --> [first book][money] = maximum page

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            dp[i][j] = dp[i - 1][j]; // not choose

            if (j - h[i] >= 0) // canbuy
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - h[i]] + s[i]);
            }
        }
    }

    cout << recur(n, x) << "\n";
    cout << dp[n][x];

    return 0;
}