#include <stdio.h>
#define max(a, b) (a > b) ? a : b

int b[10005];
int dp[10005], n;

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &b[i]);

    int b1 = 0, b2 = 0, tmp = 0;

    for (int i = 0; i < n; i++)
    {
        tmp = max(b1 + b[i], b2);
        b1 = b2;
        b2 = tmp;
    }

    printf("%d", b2);

    return 0;
}