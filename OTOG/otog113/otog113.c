#include <stdio.h>
#define N 100005
#define MAX(a, b) (a > b) ? a : b

int n;
int dp[N], arr[N];

int recur(int x)
{
    if (x > n)
        return 0;

    if (dp[x])
        return dp[x];

    int res = 0;
    res = MAX(recur(x + 3) + arr[x], recur(x + 1));

    return dp[x] = res;
}

int main()
{
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("%d", recur(3));

    return 0;
}