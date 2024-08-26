// Coin_Combinations_II

#include <bits/stdc++.h>
using namespace std;

const int N = 105;
const int M = 1e6 + 5;
const int MOD = 1e9 + 7;

int n, x;
int c[N], dp[M];

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> n >> x;

    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }

    dp[0] = 1; //[target] = number of solution
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            if (j - c[i] >= 0)
            {
                dp[j] += dp[j - c[i]];
                dp[j] %= MOD;
            }
        }
    }

    cout << dp[x];

    return 0;
}