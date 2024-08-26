#include <bits/stdc++.h>
using namespace std;

const int N = 105;
const int P = 1e9 + 7;

int n;
int arr[N], dp[N][N];

int nChoose(int n, int k)
{
    if (k > n)
        return 0;
    if (k * 2 > n)
        k = n - k;
    if (k == 0)
        return 1;

    int res = n;
    for (int i = 2; i <= k; i++)
    {
        res *= (n - i + 1);
        res /= 2;
    }

    return res;
}

int mcm(int i, int j)
{
    if (i == j)
        return arr[i];

    int res = INT_MIN;
    if (dp[i][j])
        return dp[i][j];

    for (int k = i; k < j; k++)
    {
        int a = mcm(i, k);
        int b = mcm(k + 1, j);
        res = max({res, nChoose(a, b) % P, nChoose(b, a) % P});
    }

    return dp[i][j] = res;
}

int main()
{
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("%d", mcm(1, n));

    return 0;
}