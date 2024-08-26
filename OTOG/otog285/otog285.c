#include <stdio.h>
#define N 100005
#define MAX(a, b) (a > b) ? a : b

int arr[N];
int n, m, k;

int up(int l, int r, int t)
{
    while (l < r)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] <= t)
            l = mid + 1;

        else
            r = mid;
    }

    return r;
}

int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    while (m--)
    {
        scanf("%d", &k);

        int ans = -1;
        int idx = up(0, n, k) - 1;

        ans = (idx < 0) ? -1 : arr[idx];

        printf("%d ", ans);
    }

    return 0;
}

/*
4 7
14 15 20 30
10 11 14 15 16 21 68
*/