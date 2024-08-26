#include <bits/stdc++.h>
#define rep(a, b, c) for (int i = a; i != b; i += c)
using namespace std;
using ll = long long;

const int N = 1505;
const int MOD = 1e6 + 3;

int r, c, k;
int pl[N][N], pr[N][N], mp[N][N];
int dp[N][605];
char b;

int main()
{
    scanf("%d%d%d", &r, &c, &k);

    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j <= i and j <= k; j++)
        {
            if (j == 0 or j == i)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];

            dp[i][j] %= MOD;
        }
    }

    for (int i = 1; i <= 1500; i++)
    {
        for (int j = 1; j <= 1500; j++)
        {
            pl[i][j] += pl[i - 1][j + 1];
            pr[i][j] += pr[i - 1][j - 1];

            if (i >= 601 and i <= 600 + r and j >= 601 and j <= 600 + c)
            {
                scanf(" %c", &b);
                pl[i][j] += (b == '#');
                pr[i][j] += (b == '#');
            }
        }
    }

    ll ans = 0;

    for (int a = 1; a <= r + c; a++)
    {
        for (int i = 601; i <= 600 + r; i++)
        {
            for (int j = 601; j <= 600 + c; j++)
            {
                int st = 0;
                st += pl[i][j - a] - pl[i - a][j];
                st += pl[i + a - 1][j + 1] - pl[i - 1][j + a + 1];
                st += pr[i + a][j] - pr[i][j - a];
                st += pr[i - 1][j + a - 1] - pr[i - a - 1][j - 1];

                // printf("%d %d %d %d\n", i, j, a, st);

                if (st >= k)
                {
                    ans += dp[st][k];
                    ans %= MOD;
                }
            }
        }
    }

    printf("%lld", ans);

    return 0;
}