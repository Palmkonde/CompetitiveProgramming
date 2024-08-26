#include <stdio.h>
#include <stdlib.h>
#define ll long long

ll arr[1000005];
ll n, a, sum;

int main()
{
    scanf("%lld", &n);

    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &arr[i]);
        sum += arr[i];
    }

    int cnt = 0;
    for (int i = 2; i < n; i++)
    {
        ll mean = (arr[i - 1] + arr[i] + arr[i + 1]) / 3;

        if (mean > arr[i])
        {
            sum -= arr[i];
            sum += mean;
            cnt++;
        }
    }

    printf("%lld %lld", cnt, sum);

    return 0;
}