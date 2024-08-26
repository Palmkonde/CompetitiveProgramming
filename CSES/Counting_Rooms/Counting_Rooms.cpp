#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int N = 1005;

char mp[N][N];
int di[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int n, m;
queue<pii> q;

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

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mp[i][j] == '#')
                continue;

            q.push({i, j});
            mp[i][j] = '#';
            ans++;

            while (not q.empty())
            {
                int nowx = q.front().first;
                int nowy = q.front().second;
                q.pop();

                for (int k = 0; k < 4; k++)
                {
                    int nx = nowx + di[k][0];
                    int ny = nowy + di[k][1];

                    if (nx < 0 or ny < 0 or nx >= n or ny >= m)
                        continue;
                    if (mp[nx][ny] == '#')
                        continue;

                    mp[nx][ny] = '#';
                    q.push({nx, ny});
                }
            }
        }
    }

    cout << ans;

    return 0;
}