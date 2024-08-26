#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int n, q;
    cin >> n >> q;

    string prev, a, ans;

    int fg = 0;
    for (int i = 0; i < q; i++)
    {

        cin >> a;

        if (fg)
            continue;

        if (i)
        {
            int cnt = 0;
            for (int i = 0; i < n; i++)
            {
                if (a[i] != prev[i])
                {
                    cnt++;
                }
            }

            if (cnt >= 3)
            {
                ans = prev;
                fg = 1;
            }
        }
        prev = a;
    }

    if (fg)
        cout << ans;
    else
        cout << a;

    return 0;
}