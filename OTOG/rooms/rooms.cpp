#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using pii = pair<int, int>;

const int N = 35;

int r, c;
int di[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
char mp[N][N], buff[N];
queue<pii> q;
vector<pii> warp;

int main()
{
    scanf("%d %d", &r, &c);

    for (int i = 0; i < r; i++)
    {
        scanf(" %s", buff);

        for (int j = 0; j < c; j++)
        {
            mp[i][j] = buff[j];

            if (mp[i][j] == 'A')
            {
                q.push({i, j});
            }

            else if (mp[i][j] == 'W')
            {
                warp.push_back({i, j});
            }
        }
    }

    // bfs
    int ans = 0;

    mp[q.front().first][q.front().y] = '#';

    while (not q.empty())
    {
        pii now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = now.x + di[i][0];
            int ny = now.y + di[i][1];

            if (nx < 0 or ny < 0 or nx >= r or ny >= c)
                continue;

            if (mp[nx][ny] == '#')
                continue;

            if (mp[nx][ny] == '*')
                ans++;

            if (mp[nx][ny] == 'W')
            {
                for (auto e : warp)
                {
                    if (e == now)
                        continue;

                    q.push(e);
                    mp[e.x][e.y] = '#';
                }
            }

            mp[nx][ny] = '#';
            q.push({nx, ny});
        }
    }

    printf("%d", ans);

    return 0;
}