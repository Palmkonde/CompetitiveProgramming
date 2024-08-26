#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, m;
char mp[N][N];

void solve(int x, int y, int xx, int yy)
{
    char ori = '2';
    bool f = true;

    if (x >= n or xx >= n or y >= m or yy >= m)
        return;

    // cout << x << " " << xx << " " << y << " " << yy << "\n";

    for (int i = x; i <= xx; i++)
    {
        for (int j = y; j <= yy; j++)
        {
            if (ori == '2')
            {
                ori = mp[i][j];
                continue;
            }

            if (mp[i][j] != ori)
            {
                f = false;
            }
        }
    }

    if (xx == x and yy == y)
        ori = mp[x][y];

    if (f)
        cout << ori;
    else
    {
        cout << "D";

        int mx = (xx + x) / 2; // 1
        int my = (yy + y) / 2; // 1

        solve(x, y, mx, my);           // 0,0,1,1
        solve(x, my + 1, mx, yy);      // 0,2,1,3
        solve(mx + 1, y, xx, my);      // 2,0,2,1
        solve(mx + 1, my + 1, xx, yy); // 2,2,2,3
    }
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mp[i][j];
        }
    }

    solve(0, 0, n - 1, m - 1);

    return 0;
}