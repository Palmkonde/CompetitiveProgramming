#include <bits/stdc++.h>
using namespace std;

int arr[2505];
int n;

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int mx = -1;
    int l = arr[0], s = arr[0];
    int start = 0, end = 0, tmp = 0;
    for (int i = 1; i < n; i++)
    {
        if (l + arr[i] < arr[i])
        {
            tmp = i;
            l = arr[i];
        }
        else
            l += arr[i];

        if (s < l)
        {
            s = l;
            end = i;
            start = tmp;
        }
    }

    if (s <= 0)
    {
        printf("Empty sequence");
        return 0;
    }

    for (int i = start; i <= end; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n%d", s);

    return 0;
}