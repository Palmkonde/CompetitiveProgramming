#include <stdio.h>
#include <stdlib.h>

int n;
int arr[2005];

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int start, tmp, end, bp, sn = -128;

    start = tmp = end = bp = 0;

    for (int i = 0; i < n; i++)
    {
        bp = bp + arr[i];

        if (bp < arr[i])
        {
            bp = arr[i];
            tmp = i;
        }

        if (sn < bp)
        {
            sn = bp;
            start = tmp;
            end = i;
        }
    }

    if (sn <= 0)
    {
        printf("Empty sequence");
        return 0;
    }
    else
    {
        for (int i = start; i <= end; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n%d", sn);
    }

    return 0;
}