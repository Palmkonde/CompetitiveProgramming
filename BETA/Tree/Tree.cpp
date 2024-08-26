#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n;
int arr[N], L[N];

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int idx = lower_bound(L, L + ans + 1, arr[i]) - L;
        ans = max(ans, idx);
        L[idx] = arr[i];
    }

    printf("%d", ans);

    return 0;
}