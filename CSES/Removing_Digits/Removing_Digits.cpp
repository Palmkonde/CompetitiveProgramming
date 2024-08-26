#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int dp[N];
int n;

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> n;

    fill(dp, dp + n + 1, 1e9);
    dp[0] = 0;

    for (int i = 0; i <= n; i++)
    {
        for (auto e : to_string(i))
        {
            dp[i] = min(dp[i], dp[i - (e - '0')] + 1);
        }
    }

    cout << dp[n];
    return 0;
}