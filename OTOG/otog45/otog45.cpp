#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1005;

int n, m, k;
ll mp[N][N], qs[N][N];

int main()
{
    scanf("%d%d%d", &n, &m, &k);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%lld", &mp[i][j]);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            qs[i][j] = qs[i - 1][j] + qs[i][j - 1] - qs[i - 1][j - 1] + mp[i][j];
        }
    }

    ll ans = INT_MIN;
    for (int i = k; i <= n; i++)
    {
        for (int j = k; j <= m; j++)
        {
            ans = max(ans, qs[i][j] - qs[i][j - k] - qs[i - k][j] + qs[i - k][j - k]);
        }
    }

    printf("%lld", ans);

    return 0;
}