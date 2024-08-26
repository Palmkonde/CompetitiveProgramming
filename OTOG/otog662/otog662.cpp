#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n;
int arr[N];
int64_t dp[N];

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // bt
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; i + (1 << j) <= n; j++)
        {
            int nx = i + (1 << j);
            int64_t eg = (int64_t)(dp[i] + ((int64_t)arr[i] * (1 << j)));

            dp[nx] = max(dp[nx], eg);
        }
    }

    cout << dp[n];

    return 0;
}

/*
2
3 2
*/