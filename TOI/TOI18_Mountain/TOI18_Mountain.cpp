#include <bits/stdc++.h>
#define MAX(a, b) ((a > b) ? a : b)
#define MIN(a, b) ((a < b) ? a : b)
using namespace std;
using ll = long long;

const int N = 505;
const int M = 200005;

ll n, m;
ll x[N], y[N], st[M];
ll dp[N][N]; // state ระหว่าง จำนวนจุดพัก, กับ node ที่จะไป = กำลังของคนที่ปีนเขาที่มากที่สุดที่เป็นไปได้

ll f(int i, int j)
{
    return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i];
    }

    for (int i = 1; i <= m; i++)
    {
        cin >> st[i];
    }

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            dp[i][j] = INT64_MAX;

    dp[0][1] = 0;                // จุดเริ่ม
    for (int k = 1; k <= n; k++) // จุดแวะที่ k
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dp[k][i] = MIN(dp[k][i], MAX(dp[k - 1][j], f(i, j)));
                // ใช้จุดแวะ k จุดไปที่จุด i จะเทียบระหว่างใช้
                // ระยะจากที่จากจุดใดๆ ก่อนหน้านี้ที่เป็นจุดแวะพัก กับการเดินไปเลยโดนไม่ผ่านจุดแวะก่อนหน้า
            }
        }
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << dp[i][n] << " ";
    // }

    int ans = 0;

    for (int i = 1; i <= m; i++)
    {
        int l = 0, r = n;
        while (l < r)
        {
            int mid = l + (r - l) / 2;

            if (dp[mid][n] > st[i])
            {
                l = mid + 1;
            }
            else
                r = mid;
        }

        ans += l;
    }

    cout << ans;

    return 0;
}

/*
5 2
0 1
2 2
3 6
6 6
9 10
10
15
*/