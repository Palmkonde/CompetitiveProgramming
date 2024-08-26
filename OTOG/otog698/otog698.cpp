#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int t, k;
int odd[N], pref[N];
int64_t dp[N];

int64_t fib(int n)
{
    if (dp[n] != 0)
        return dp[n];

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> t;

    odd[0] = pref[0] = 1;
    dp[0] = 1;
    dp[1] = 2;
    for (int i = 1; i <= N; i++)
    {
        odd[i] = odd[i - 1] + 2;
        pref[i] += pref[i - 1] + odd[i];
    }

    while (t--)
    {
        cin >> k;

        auto l = lower_bound(pref, pref + N, k) - pref;

        printf("%lld\n", fib(l));
    }

    return 0;
}