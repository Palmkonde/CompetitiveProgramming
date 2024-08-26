#include <bits/stdc++.h>
using namespace std;

int a[105];
int m, o;

int main()
{
    scanf("%d%d", &o, &m);

    int l = 1, r = 0;
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &a[i]);
        l = max(l, a[i]);
        r += a[i];
    }

    while (l < r)
    {
        int sum = 0, cnt = 0;
        int mid = l + (r - l) / 2;
        for (int i = 0; i < m; i++)
        {
            if (sum + a[i] > mid)
            {
                cnt++;
                sum = 0;
            }
            sum += a[i];
        }

        if (!sum)
            cnt++;

        // printf("%d %d %d", l, mid, r);
        // printf(" %d\n", cnt);

        if (cnt < o)
        {
            r = mid;
        }
        else
            l = mid + 1;
    }

    printf("%d", l);

    return 0;
}

/*
3 6
800
800
800
800
800
800
*/