#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, m;
int arr[N];

int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int k;
    while (m--)
    {
        scanf("%d", &k);

        auto idx = upper_bound(arr, arr + n, k) - arr;
        idx--;

        printf("%d\n", idx);
    }

    return 0;
}