#include <bits/stdc++.h>
using namespace std;

const int N = 10005;

string a, b;
int dp[N][N];

int main()
{
    cin >> a;
    cin >> b;

    int n = a.size();
    int m = b.size();

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    string ans = "";

    int i = n, j = m;

    while (i > 0 and j > 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            ans += a[i - 1];
            i--;
            j--;
        }

        else
        {
            if (dp[i][j - 1] > dp[i - 1][j])
            {
                j--;
            }
            else
                i--;
        }
    }

    reverse(ans.begin(), ans.end());
    cout << ans;

    return 0;
}