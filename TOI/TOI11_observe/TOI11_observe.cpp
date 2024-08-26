#include <bits/stdc++.h>
using namespace std;

const int N = 2005;

int m, n, k;
int mp[N][N];

int pf[N][N], rpf[N][N];
int sq[N][N], rsq[N][N];

// 2D prefix sum
int main()
{
    scanf("%d%d%d", &n, &m, &k);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &mp[i][j]);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            pf[i][j] = mp[i][j] + pf[i][j - 1] + pf[i - 1][j - 1] - pf[i - 1][j - 2];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            sq[i][j] = mp[i][j] + sq[i - 1][j] + sq[i][j - 1] - sq[i - 1][j - 1];
        }
    }

    int ans = INT_MIN;
    for (int i = n; i >= k; i--)
    {
        for (int j = m; j >= k; j--)
        {
            ans = max(ans, pf[i][j] - sq[i][j - k] + sq[i - k][j - k] - pf[i - k][j - k]);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= 1; j--)
        {
            rpf[i][j] = mp[i][j] + rpf[i - 1][j + 1] + rpf[i][j + 1] - rpf[i - 1][j + 2];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= 1; j--)
        {
            rsq[i][j] = mp[i][j] + rsq[i - 1][j] + rsq[i][j + 1] - rsq[i - 1][j + 1];
        }
    }

    for (int i = n; i >= k; i--)
    {
        for (int j = 1; j <= m - k + 1; j++)
        {
            ans = max(ans, rpf[i][j] - rsq[i][j + k] + rsq[i - k][j + k] - rpf[i - k][j + k]);
        }
    }

    printf("%d", ans);

    return 0;
}