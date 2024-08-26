#include <bits/stdc++.h>
using namespace std;

int n;
int arr[505];

int mcm(int l, int r)
{
    if (l >= r)
        return -1e5;

    int res = -1e5;
    for (int k = l; k < r; k++)
    {
        res = max({res, mcm(l, k) + mcm(k + 1, r) + (arr[l] + arr[r])});
    }
      
    return res;
}

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("%d", mcm(0, n - 1));

    return 0;
}