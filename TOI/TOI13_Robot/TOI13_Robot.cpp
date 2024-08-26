#include <bits/stdc++.h>
using namespace std;
using tiii = tuple<int, int, int>;

const int N = 2005;

int n, m;
int di[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
char mp[N][N];
queue<tiii> q;

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mp[i][j];

            if (mp[i][j] == 'X')
            {
                q.push({i, j, 0});
            }
        }
    }

    int cnt = 0, ans = 0;
    while (not q.empty())
    {
        int qs = q.size();
        while (qs--)
        {
            int x, y, stp;
            tie(x, y, stp) = q.front();
            q.pop();

            // printf("%d %d %d\n", x, y, stp);

            mp[x][y] = 'W';

            for (int i = 0; i < 4; i++)
            {
                int nx = x + di[i][0];
                int ny = y + di[i][1];
                if (nx < 0 or ny < 0 or nx >= n or ny >= m)
                    continue;

                if (mp[nx][ny] == 'W')
                    continue;

                if (mp[nx][ny] == 'A')
                {
                    cnt++;
                    ans += ((stp + 1) << 1);
                }

                mp[nx][ny] = 'W';
                q.push({nx, ny, stp + 1});
            }
        }
    }

    cout << cnt << " " << ans;

    return 0;
}