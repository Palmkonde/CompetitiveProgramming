#include <bits/stdc++.h>
using namespace std;

int n, x;
int arr[25], dp[10005];

int main()
{
    scanf("%d%d", &n, &x);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    fill(dp, dp + x + 1, 1e9);
    dp[0] = 0;

    for (int w = 0; w <= x; w++)
    {
        for (int i = 0; i < n; i++)
        {
            if (w - arr[i] >= 0)
                dp[w] = min(dp[w], dp[w - arr[i]] + 1);
        }
    }

    printf("%d", dp[x]);

    return 0;
}