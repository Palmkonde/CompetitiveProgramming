#include <bits/stdc++.h>
using namespace std;

const int N = 105;
const int M = 1e6 + 5;
const int MOD = 1e9 + 7;

int n, x;
int coin[N], dp[M];

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> coin[i];
    }

    // intial
    fill(dp, dp + x + 1, 1e9);
    dp[0] = 0; //[target] = min of coin

    for (int i = 1; i <= x; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i - coin[j] >= 0)
            {
                dp[i] = min(dp[i], dp[i - coin[j]] + 1);
            }
        }
    }

    if (dp[x] == 1e9)
    {
        cout << "-1";
    }
    else
        cout << dp[x];

    return 0;
}