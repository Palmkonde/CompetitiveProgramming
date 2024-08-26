#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, x;
int pi[N];

int main()
{
    scanf("%d%d", &n, &x);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &pi[i]);
    }

    sort(pi, pi + n);

    // for (int i = 0; i < n; i++)
    //     printf("%d ", pi[i]);

    int ans = 0;
    int now = 0, c = 0;
    int l = 0, r = n - 1;

    while (l <= r)
    {
        if (pi[l] + pi[r] > x)
        {
            r--;
            ans++;
        }

        else
        {
            l++;
            r--;
            ans++;
        }
    }

    printf("%d", ans);

    return 0;
}