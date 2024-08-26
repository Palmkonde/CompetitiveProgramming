// Coin_Combinations_I

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int N = 105;
const int M = 1e6 + 5;

int n, x;
int dp[M], coin[N];

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> n >> x;

    for (int i = 0; i < n; i++)
    {
        cin >> coin[i];
    }

    dp[0] = 1; //[target] = number of solution
    for (int i = 0; i <= x; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i - coin[j] >= 0)
            {
                dp[i] += dp[i - coin[j]];
                dp[i] %= MOD;
            }
        }
    }

    cout << dp[x];

    return 0;
}