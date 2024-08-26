#include <stdio.h>
#define ll long long

int n, l, r, d;
int dp[200000005];

int recur(int x)
{
    if (dp[x])
        return dp[x];

    if (x < d)
        return 1;

    int hl = (x / (double)d) * l;
    int hr = (x / (double)d) * r;
    int res = 0;

    res += (hl < d) ? 1 : recur(hl);
    res += (hr < d) ? 1 : recur(hr);

    return dp[x] = res;
}

int main()
{
    scanf("%d%d%d", &n, &l, &r);

    d = l + r;

    printf("%d", recur(n));

    return 0;
}