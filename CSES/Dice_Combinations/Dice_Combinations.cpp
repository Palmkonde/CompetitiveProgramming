#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

int n;
int dp[N];

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> n;

    dp[0] = 1; //[target] = number of solution

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            if (i - j >= 0)
            {
                dp[i] += dp[i - j];
                dp[i] %= MOD;
            }
        }
    }

    cout << dp[n];

    return 0;
}