#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int N = 1005;

int n;
int dp[N];

int main()
{
    cin >> n;

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 5;

    for (int i = 4; i <= n; i++)
    {
        dp[i] = (2 * dp[i - 1]) % MOD + (dp[i - 3]);
        dp[i] %= MOD;
    }

    cout << dp[n];

    return 0;
}