#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int mx = INT_MIN;
int cnt, n, arr[N];

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        mx = max(mx, arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        cnt += (arr[i] == mx) ? 1 : 0;
    }

    printf("%d", cnt);

    return 0;
}