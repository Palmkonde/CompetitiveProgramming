#include <stdio.h>
#include <stdlib.h>
#define N 10005

int w, h, n, x, a;
int arr[N];
int ft, oh;

int main()
{
    scanf("%d %d %d", &w, &h, &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &x, &a);

        arr[x] += 1;
        arr[x + a] -= 1;
    }

    int temp = 0;
    for (int i = 0; i < w; i++)
    {
        temp += arr[i];
        arr[i] = temp;

        if (arr[i] == 0)
        {
            oh += h;
        }
        else if (arr[i] == 1)
        {
            ft += h;
        }
    }

    printf("%d %d", oh, ft);

    return 0;
}