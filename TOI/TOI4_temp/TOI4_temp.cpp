#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int M = 25;

int mp[M][M];
int di[][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int m, ans;
bool vis[M][M];
pii st;
queue<pii> q;

int main()
{
    scanf("%d", &m);
    scanf("%d%d", &st.first, &st.second);

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &mp[i][j]);
        }
    }

    vis[st.second][st.first] = true;
    ans = mp[st.second][st.first];
    q.push({st.second, st.first});

    while (not q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // printf("%d %d\n", x, y);

        for (int i = 0; i < 4; i++)
        {
            int nx = x + di[i][0];
            int ny = y + di[i][1];

            if (nx < 1 or ny < 1 or nx > m or ny > m)
                continue;
            if (vis[nx][ny] or mp[nx][ny] == 100)
                continue;
            if (mp[nx][ny] <= mp[x][y])
                continue;

            vis[nx][ny] = true;
            ans = max(ans, mp[nx][ny]);
            q.push({nx, ny});
        }
    }

    printf("%d", ans);

    return 0;
}