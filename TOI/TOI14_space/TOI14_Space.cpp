#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

struct pii
{
    int x;
    int y;
};

char mp[2005][10005];
bool vis[2005][10005];
int n, m, x, y;
int ans[3];
std::queue<pii> q;

int main()
{
    cin >> m >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mp[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mp[i][j] != '0' and !vis[i][j])
            {
                vis[i][j] = true;
                q.push({i, j});

                int cnt = 0;
                while (not q.empty())
                {
                    int tmp = 0;
                    x = q.front().x;
                    y = q.front().y;
                    q.pop();

                    for (int k = -1; k <= 1; k++)
                    {
                        for (int l = -1; l <= 1; l++)
                        {
                            if (abs(k) == abs(l))
                                continue;

                            int nx = x + k;
                            int ny = y + l;
                            bool fg = false;
                            if (vis[nx][ny])
                                continue;

                            if (nx < 0 or ny < 0 or nx >= n or ny >= m)
                            {
                                fg = true;
                                tmp++;
                            }

                            if (mp[nx][ny] == '0')
                            {
                                fg = true;
                                tmp++;
                            }

                            if (tmp >= 3)
                            {
                                cnt++;
                                tmp = 0;
                            }

                            if (fg)
                                continue;

                            vis[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                }

                if (cnt > 3)
                    ans[1]++;
                else if (cnt > 0)
                    ans[2]++;
                else
                    ans[0]++;
            }
        }
    }

    printf("%d %d %d", ans[0], ans[1], ans[2]);

    return 0;
}