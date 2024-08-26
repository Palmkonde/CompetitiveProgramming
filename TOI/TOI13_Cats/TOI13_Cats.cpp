#include <bits/stdc++.h>
using namespace std;

const int N = 2000005;
int64_t cat[N], n;

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> n;

    int64_t mx = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> cat[i];
        mx = max(mx, cat[i]);
    }

    int64_t l = 0, r = mx, ans;

    while (l < r)
    {
        int64_t mid = l + (r - l) / 2;

        int fg = 0;
        int64_t last = -1;
        for (int i = 0; i < n; i++)
        {
            if (cat[i] > mid)
            {
                if (last == -1)
                {
                    last = cat[i];
                    continue;
                }
                else if (last != cat[i])
                {
                    fg = 1;
                    break;
                }
                else
                {
                    last = -1;
                }
            }
        }

        if (!fg)
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout << l;

    return 0;
}