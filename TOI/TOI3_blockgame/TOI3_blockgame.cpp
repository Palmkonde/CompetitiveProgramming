#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int di[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
char mp[10][10];

int dfs(int x, int y, char &wnt)
{
    int res = 0;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + di[i][0];
        int ny = y + di[i][1];

        if (mp[nx][ny] != wnt)
            continue;

        mp[nx][ny] = '-';
        res = dfs(nx, ny, wnt);
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

    cin >> k;

    int a, b;
    char c;
    int score = 0;
    while (k--)
    {
        cin >> a >> b >> c;

        if (c == 'L')
        {
            if (mp[a][b - 1] == '#')
            {
                score -= 5;
            }

            else if (mp[a][b - 1] == '-')
            {
            }
        }
    }

    return 0;
}