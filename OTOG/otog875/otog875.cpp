#include <bits/stdc++.h>
using namespace std;

int n, x, y, stx, sty;
char c[1000005];

void solve(int tmp)
{
    vector<int> factors;
    int res = INT_MAX;
    bool fg = tmp < 0;
    for (int i = 1; i * i <= abs(tmp); i++)
    {
        // printf("%d ", i);
        if (abs(tmp) % i == 0)
        {
            factors.push_back(tmp / i);
            factors.push_back((fg) ? -i : i);
        }
    }

    for (auto e : factors)
    {
        res = min(res, abs(stx - e));
    }
    printf("%d", res);
}

int main()
{
    scanf("%d%d%d", &n, &x, &y);

    scanf("%s", c);
    for (int i = 0; i < n; i++)
    {
        if (c[i] == 'U')
            sty++;
        else if (c[i] == 'L')
            stx--;
        else if (c[i] == 'R')
            stx++;
        else if (c[i] == 'D')
            sty--;
    }

    if (x == 0 and y == 0)
    {
        printf("%d", abs(stx) + abs(sty));
        return 0;
    }

    else if (x == 0 or y == 0)
    {
        int tmp = (x == 0) ? y : x;
        solve(tmp);
    }
    else
    {
        int gcd = __gcd(abs(x), abs(y));
        int sx = x / gcd;
        int sy = y / gcd;

        printf("%d", abs(sx - stx) + abs(sy - sty));
    }

    return 0;
}

/*
12 -1261 0
RLLLLLLLLLLL
*/
