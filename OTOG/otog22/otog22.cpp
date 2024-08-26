#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int N = 1005;

int n, m;
int di[8][2] = {{1, 2}, {-1, 2}, {1, -2}, {-1, -2}, {2, 1}, {-2, 1}, {2, -1}, {-2, -1}};
char mp[N][N];
pii st, ed;
queue<pair<pii, int>> q;

int main()
{
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> mp[i][j];
        }
    }

    scanf("%d%d", &st.first, &st.second);
    scanf("%d%d", &ed.first, &ed.second);

    q.push({st, 0});

    int ans = -1;
    while (not q.empty())
    {
        pii now = q.front().first;
        int step = q.front().second;
        q.pop();

        mp[now.first][now.second] = 'X';

        if (now == ed)
        {
            ans = step;
        }

        for (int i = 0; i < 8; i++)
        {
            int nx = now.first + di[i][0];
            int ny = now.second + di[i][1];

            if (mp[nx][ny] == 'X')
                continue;
            if (nx < 1 or ny < 1 or nx > n or ny > m)
                continue;

            mp[nx][ny] = 'X';
            q.push({{nx, ny}, step + 1});
        }
    }

    printf("%d", ans);

    return 0;
}