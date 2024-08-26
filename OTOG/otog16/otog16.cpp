#include <bits/stdc++.h>
using namespace std;

const int N = 2505;

int n, bp, sn;
int arr[N];

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    sn = INT_MIN;
    int tmp = 0, start = 0, end = 0;
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

    if (sn < 0)
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