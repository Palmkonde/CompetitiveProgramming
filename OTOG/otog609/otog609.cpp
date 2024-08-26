#include <bits/stdc++.h>
using namespace std;

const int N = 10005;

int n;
int arr[N], qs[N];

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    sort(arr, arr + n);

    qs[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        qs[i] += qs[i - 1] + arr[i];
    }

    int k;
    while (scanf("%d", &k) != EOF)
    {
        auto idx = lower_bound(qs, qs + n + 1, k);

        if (k < *idx)
        {
            k = *idx - k;
            auto aa = lower_bound(qs, qs + n + 1, k);

            if (aa != qs + n + 1)
            {
                if (k - *aa != 0)
                    printf("NO\n");
                else
                    printf("YES\n");
            }
            else
                printf("NO\n");
        }

        else if (k == *idx)
        {
            printf("YES\n");
        }
    }

    return 0;
}