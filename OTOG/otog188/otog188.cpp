#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

ull dp[45];
ull n;

int main()
{
    cin >> n;

    ull last = 1;
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = (last * 3 - 1) + dp[i - 1];
        last = last * 3 - 1;
    }

    cout << dp[n];

    return 0;
}