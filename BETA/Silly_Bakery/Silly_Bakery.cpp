#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    int a, b, c, d, e, x, n;
    a = b = c = d = e = 0;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        a += x;

        cin >> x;
        b += x;

        cin >> x;
        c += x;

        cin >> x;
        d += x;

        cin >> x;
        e += x;
    }

    cout << ceil((a * 8 + b * 6 + c * 4 + d * 2 + e) / 8.0);

    return 0;
}