#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int n, m;
int mp[50][50];
pii st, ed;
bool visited[50][50];
int di[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

int dfs(int x, int y, int hp)
{

    if (x < 0 or y < 0 or x >= n or y >= m)
        return -99;
    if (hp < 1)
        return -99;

    if (x == ed.first and y == ed.second)
    {
        return hp;
    }

    visited[x][y] = true;
    int res = -99;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + di[i][0];
        int ny = y + di[i][1];

        if (visited[nx][ny])
            continue;

        res = max(res, dfs(nx, ny, hp + mp[nx][ny]));
    }
    visited[x][y] = false;

    return res;
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char x;
            cin >> x;

            if (x == 'S')
            {
                st = {i, j};
            }

            if (x == 'E')
            {
                ed = {i, j};
            }

            if (x == '*')
                mp[i][j] = 1;
            else if (x == 'X')
                mp[i][j] = -1;
            else
                mp[i][j] = 0;
        }
    }

    cout << dfs(st.first, st.second, 3);

    return 0;
}