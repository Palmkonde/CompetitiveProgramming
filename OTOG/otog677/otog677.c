#include <stdio.h>
#include <stdlib.h>
#define MAX(a, b) (a > b) ? a : b
typedef struct PII
{
    int first;
    int second;
} PII;

PII make_pair(int a, int b)
{
    PII new;
    new.first = a;
    new.second = b;

    return new;
}

int n, m;
PII s, e;
char tmp;
int mp[10][10], vis[10][10];
int di[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

int dfs(int x, int y, int hp)
{
    if (hp < 1)
        return -99;
    if (x < 0 || y < 0 || x >= n || y >= m)
        return -99;

    if (x == e.first && y == e.second)
    {
        return hp;
    }

    vis[x][y] = 1;
    int res = -99;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + di[i][0];
        int ny = y + di[i][1];

        if (vis[nx][ny] == 1)
        {
            continue;
        }

        res = MAX(res, dfs(nx, ny, hp + mp[nx][ny]));
    }

    vis[x][y] = 0;
    return res;
}

int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf(" %c", &tmp);

            mp[i][j] += (tmp == '*') ? 1 : -1;

            if (tmp == 'S')
            {
                mp[i][j] = 0;
                s = make_pair(i, j);
            }

            if (tmp == 'E')
            {
                mp[i][j] = 0;
                e = make_pair(i, j);
            }
        }
    }

    printf("%d", dfs(s.first, s.second, 3));

    return 0;
}