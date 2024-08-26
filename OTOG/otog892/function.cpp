#include <bits/stdc++.h>
#include "function.h"
using namespace std;
using ll = long long;

const ll inf = 1e18;
const int K = 1005;

ll dp[K][K], dp2[K][25];
ll pf[K];
int a[K];
int n;

ll f(int l, int r)
{
    if (dp[l][r] != 0)
        return dp[l][r];

    ll res = 0;
    for (int i = l; i <= r; i++)
    {
        res += (pf[r] - pf[i - 1]) * a[i];
    }

    return dp[l][r] = res;
}

ll solve(int s, int m)
{
    if (dp2[s][m] != 0)
        return dp2[s][m];

    if (m == 1)
        return f(1, s);

    if (s < 0)
        return inf;

    ll res = inf;
    for (int i = 1; i <= s; i++)
    {
        res = min({res, solve(i, m - 1) + f(i + 1, s)});
    }

    return dp2[s][m] = res;
}

long long minPenguinValue(int N, int M, std::vector<int> A)
{
    ll res = 0;
    n = N;
    for (int i = 1; i <= N; i++)
        a[i] = A[i - 1];

    for (int i = 1; i <= N; i++)
    {
        pf[i] = pf[i - 1] + a[i];
    }

    res = solve(N, M);
    return res;
}

// int main()
// {
//     cout << minPenguinValue(3, 1, {1, 2, 3});
// }