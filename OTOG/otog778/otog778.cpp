#include <bits/stdc++.h>
using namespace std;

int n, l, r, d, mx = 0;
int dp[200'000'000];

int recur(int n)
{
    int ll = ((n * l) / d);
    int rr = ((n * r) / d);
    int res = 0;
    if (dp[n])
        return dp[n];
    if (ll < d)
    {
        res++;
    }
    else
        res += recur(ll);

    if (rr < d)
    {
        res++;
    }
    else
        res += recur(rr);

    return dp[n] = res;
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    scanf("%d %d %d", &n, &l, &r);
    d = l + r;

    cout << recur(n);
    return 0;
}