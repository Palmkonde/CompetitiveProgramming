#include <stdio.h>
#include <stdlib.h>
#define N 200005
#define MAX(a, b) (a > b) ? a : b

int n;
int arr[N], L[N];

int lw(int l, int r, int target)
{
    while (l < r)
    {
        int mid = l + (r - l) / 2;

        if (L[mid] < target)
        {
            l = mid + 1;
        }
        else
            r = mid;
    }

    return r;
}

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
        int idx = lw(0, ans + 1, arr[i]);
        ans = MAX(ans, idx);
        L[idx] = arr[i];
    }

    printf("%d", ans);

    return 0;
}