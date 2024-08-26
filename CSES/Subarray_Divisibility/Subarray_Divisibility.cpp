#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int64_t n, arr[N];

int main()
{
    scanf("%d", &n);

    int64_t qs = 0, ans = 0;
    vector<int> nums(n, -1);

    nums[0] = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &arr[i]);

        qs = ((qs + arr[i]) % n + n) % n;

        printf("%d ", qs);

        ans += ++nums[qs];
    }

    printf("\n%lld", ans);

    return 0;
}