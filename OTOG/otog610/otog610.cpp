#include <bits/stdc++.h>
using namespace std;

const uint64_t N = 1e18;

uint64_t n, s;

int main()
{
    scanf("%llu%llu", &n, &s);

    uint64_t l = 0, r = n + 1, mid, x, con;
    string tmp;

    while (l < r)
    {
        mid = l + (r - l) / 2;

        tmp = to_string(mid);
        x = 0;
        for (int i = 0; i < tmp.size(); i++)
        {
            x += tmp[i] - '0';
        }
        con = mid - x;

        if (con < s)
        {
            l = mid + 1;
        }
        else
            r = mid;
    }

    cout << (n - r) + 1 << "\n";
    if (n - r + 1 == 0)
    {
        cout << -1;
    }
    else
        cout << n;

    return 0;
}