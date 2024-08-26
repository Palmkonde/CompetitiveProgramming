#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int n, x;
pii a[5005];

int main()
{
    scanf("%d%d", &n, &x);

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i].first);
        a[i].second = i;
    }

    sort(a + 1, a + n + 1);

    for (int i = 1; i <= n; i++)
    {
        int temp = x - a[i].first;
        int l = i + 1;
        int r = n;

        while (l < r)
        {
            if (a[l].first + a[r].first == temp)
            {
                printf("%d %d %d", a[i].second, a[l].second, a[r].second);
                return 0;
            }

            if (a[l].first + a[r].first > temp)
                r--;
            else
                l++;
        }
    }

    printf("IMPOSSIBLE");

    return 0;
}