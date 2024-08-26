#include <bits/stdc++.h>
using namespace std;

int n, l, h, r;
int dp[260];

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d", &l, &h, &r);
        for (int i = l; i < r; i++)
        {
            dp[i] = max(dp[i], h);
        }
    }

    for (int i = 1; i <= 255; i++)
    {
        if (dp[i] != dp[i - 1])
            cout << i << " " << dp[i] << " ";
    }

    return 0;
}
