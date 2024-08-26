#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define max(a, b) (a > b) ? a : b;

int n, l, h, r;
int arr[300];

int main()
{
    scanf("%d", &n);

    int mx = -1;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d", &l, &h, &r);

        mx = max(r, mx);

        for (int i = l; i < r; i++)
        {
            arr[i] = max(arr[i], h);
        }
    }

    for (int i = 1; i <= mx + 1; i++)
    {
        if (arr[i] != arr[i - 1])
            printf("%d %d ", i, arr[i]);
    }

    return 0;
}