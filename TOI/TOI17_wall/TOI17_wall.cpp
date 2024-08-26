#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int N = 1005;

int r, c;
int di[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
char mp[N][N], buff[N];
bool vis[N][N];
queue<pii> q;

int slove(int x, int y)
{
    int res = 0;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + di[i][0];
        int ny = y + di[i][1];

        if (mp[nx][ny] == '.' and vis[nx][ny] == true)
            res++;

        if (mp[nx][ny] == 'X' and !vis[nx][ny])
        {
            vis[nx][ny] = true;
            res += slove(nx, ny);
        }
    }

    return res;
}

int main()
{
    scanf("%d %d", &r, &c);

    for (int i = 0; i < r; i++)
    {
        scanf("%s", buff);
        for (int j = 0; j < c; j++)
        {
            mp[i][j] = buff[j];
        }
    }

    // for (int i = 0; i < r; i++)
    // {
    //     for (int j = 0; j < c; j++)
    //     {
    //         printf("%c", mp[i][j]);
    //     }
    //     printf("\n");
    // }

    for (int i = 0; i < r; i++)
    {
        q.push({i, 0});
        q.push({i, c - 1});

        vis[i][0] = true;
        vis[i][c - 1] = true;
    }

    for (int i = 0; i < c; i++)
    {
        q.push({0, i});
        q.push({r - 1, i});

        vis[0][i] = true;
        vis[r - 1][i] = true;
    }

    while (not q.empty())
    {
        int nowx = q.front().first;
        int nowy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = nowx + di[i][0];
            int ny = nowy + di[i][1];

            if (nx < 0 or ny < 0 or nx >= r or ny >= c)
                continue;

            if (mp[nx][ny] == 'X')
                continue;

            if (vis[nx][ny])
                continue;

            vis[nx][ny] = true;
            q.push({nx, ny});
        }
    }

    int ans = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (mp[i][j] == 'X')
            {
                vis[i][j] = true;
                ans = max(ans, slove(i, j));
            }
        }
    }

    printf("%d", ans);

    return 0;
}
/*
4 6
......
.X.X..
.X.XX.
......

4 6
......
.X.X..
..X.X.
......

5 5
.....
..X..
.X.X.
..X..
.....
*/