#include <bits/stdc++.h>
using namespace std;

const int N = 20005;

int num[N], n, q, a, b, s, e;

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    scanf("%d %d", &n, &q);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
    }
    sort(num, num + n);

    while (q--)
    {
        scanf("%d %d %d %d", &a, &b, &s, &e);
        a--, b--;
        auto stp = lower_bound(num + a, num + b, s);
        auto edp = lower_bound(num + a, num + b, e);

        if (*edp > e)
            edp -= 1;

        cout << ((edp - num) - (stp - num)) + 1 << " ";
    }

    return 0;
}