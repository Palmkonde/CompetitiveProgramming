#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int64_t arr[N];
int n, x;

int main()
{
    scanf("%d%d", &n, &x);

    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &arr[i]);
    }

    int ans = 0;
    int64_t sum = 0;

    for (int l = 0, r = 0; r < n; r++)
    {
        sum += arr[r];

        while (sum > x)
        {
            sum -= arr[l++];
        }

        if (sum == x)
            ans++;
    }

    printf("%d", ans);

    return 0;
}