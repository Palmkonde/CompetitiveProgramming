#include <bits/stdc++.h>
using namespace std;

const int MAXN = 70;

char mp[MAXN][MAXN] = {'0'};
int n;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;

    for (int i = 0; i <= n + 1; i++)
    {
        for (int j = 0; j <= n + 1; j++)
        {
            mp[i][j] = '#';
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> mp[i][j];
        }
    }

    queue<pair<int, int>> q;
    int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
    mp[n + 1][n] = mp[n][n + 1] = mp[1][0] = mp[0][1] = '0';
    int cnt = 0;

    q.push({1, 1});
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (mp[x][y] == '0')
            continue;
        mp[x][y] = '0';

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (mp[nx][ny] == '#')
            {
                cnt++;
            }
            else if (mp[nx][ny] == '0')
                continue;
            else if (mp[nx][ny] == '.')
            {
                q.push({nx, ny});
            }
        }
    }

    cout << cnt * 9;
    return 0;
}