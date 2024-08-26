#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int m, n;
double mn = INT_MAX;
bool vis[5][5];
int di[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
double mp[5][5];

void cal(int i, int j, double much)
{
    for (int k = 0; k < 8; k++)
    {
        int nx = i + di[k][0];
        int ny = j + di[k][1];

        if (nx < 0 or ny < 0 or nx >= m or ny >= n)
            continue;

        mp[nx][ny] += much;
    }
}

void recur(int cnt, double now)
{
    if (cnt == m * n)
    {
        mn = min(mn, now);
        return;
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (vis[i][j])
                continue;
            vis[i][j] = true;
            cal(i, j, mp[i][j] * 0.10);
            recur(cnt + 1, now + mp[i][j]);
            cal(i, j, -(mp[i][j] * 0.10));
            vis[i][j] = false;
        }
    }
}

int main()
{
    scanf("%d%d", &m, &n);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%lf", &mp[i][j]);
        }
    }

    recur(0, 0.0);
    printf("%.2lf", mn);

    return 0;
}