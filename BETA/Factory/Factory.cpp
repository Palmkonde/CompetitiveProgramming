#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int arr[N], n, a, b;
int l = INT_MAX;

int main()
{
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
        arr[i] += arr[i - 1];
    }

    int sum = arr[n];

    for (int i = 1; i <= n; i++)
    {
        int ra = arr[i];
        for (int j = i + 1; j <= n; j++)
        {
            int rb = arr[j] - arr[i];
            int rc = sum - (ra + rb);

            int mx = max({ra, rb, rc});
            int mn = min({ra, rb, rc});

            if (mx - mn < l)
            {
                l = (mx - mn);
                a = i + 1;
                b = (j + 1 > n) ? n : j + 1;
            }
        }
    }

    printf("%d %d", a, b);

    return 0;
}