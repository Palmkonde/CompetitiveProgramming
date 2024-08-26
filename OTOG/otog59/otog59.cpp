#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n;
int a[N];
int b[N];

int x, y = INT_MAX;

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &b[i]);
    }

    sort(b, b + n, greater<int>());
    sort(a, a + n);

    int mn = INT_MAX, mx = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        mn = min(a[i], b[i]);
        mx = max(a[i], b[i]);

        if ((x <= mn and mn <= y))
        {
            x = mn;
        }

        if (x <= mx and mx <= y)
        {
            y = mx;
        }
    }

    printf("%d", x);

    return 0;
}