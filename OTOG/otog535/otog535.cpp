#include <bits/stdc++.h>
using namespace std;

const int N = 3005;

string a, b;
int dp[N][N][5];

int LCS(int i, int j, int k)
{
    int res = 0;
    if (i < 0 or j < 0)
        return 0;

    if (dp[i][j][k])
        return dp[i][j][k];

    if (a[i] == b[j])
    {
        res = LCS(i - 1, j - 1, k) + 1;
    }
    else
    {
        res = max(LCS(i - 1, j, k), LCS(i, j - 1, k));
    }

    return dp[i][j][k] = res;
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    int k = 0;
    while (cin >> a >> b)
    {
        cout << LCS(a.length() - 1, b.length() - 1, k++) << "\n";
    }
    return 0;
}