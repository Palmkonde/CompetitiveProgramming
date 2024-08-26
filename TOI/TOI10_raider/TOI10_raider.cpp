#include <bits/stdc++.h>
using namespace std;
using tii = tuple<int, int, int>;

const int N = 205;

int n, m;
int di[6][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, 1}, {1, 1}};
int mp[N][N];
bool vis[N][N][505];
queue<tii> q;

int main()
{
    scanf("%d %d", &n, &m);

    if (n > 100 or m > 100)
        return 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &mp[i][j]);
        }
    }

    int ay = (n - 1) / 2;
    for (int i = -1; i <= 1; i++)
    {
        if (mp[ay + i][0] == 1)
            q.push({ay + i, 0, 1});
    }

    int mn = INT_MAX;
    while (not q.empty())
    {
        int nowx, nowy, stp;

        tie(nowx, nowy, stp) = q.front();
        q.pop();

        if (vis[nowx][nowy][stp])
            continue;
        vis[nowx][nowy][stp] = true;

        if (nowx == ay and nowy == m - 1)
        {
            printf("%d", stp);
            return 0;
        }

        for (int i = 0; i < 6; i++)
        {
            int nx = nowx + di[i][0];
            int ny = nowy + di[i][1];

            if (nowx % 2 == 1)
                ny = nowy - di[i][1];
            if (nx < 0 or ny < 0 or nx >= n or ny >= m)
                continue;
            if (mp[nx][ny] == 0)
                continue;
            if ((stp + 1) % mp[nx][ny] != 0)
                continue;

            q.push({nx, ny, stp + 1});
        }
    }

    return 0;
}