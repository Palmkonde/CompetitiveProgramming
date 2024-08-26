#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int n, m, f;
int mp[N][N][N], dp[N][N][N];

int recur(int x, int y, int z)
{
    if (x < 1 or y < 1 or z < 1 or x > n or y > m or z > f)
        return 0;

    int res = 0;

    if (x == n and y == m and mp[x][y][z] < 0)
    {
        return max(mp[x][y][z], recur(x, y, z + 1) + abs(mp[x][y][z]));
    }

    if (x == n and y == m)
        return mp[x][y][z];

    if (dp[x][y][z])
        return dp[x][y][z];

    res = max({res, recur(x + 1, y, z) + abs(mp[x][y][z]), recur(x, y + 1, z) + abs(mp[x][y][z])});
    if (mp[x][y][z] < 0)
    {
        res = max({res, recur(x, y, z + 1) + abs(mp[x][y][z])});
    }

    return dp[x][y][z] = res;
}

int main()
{
    scanf("%d %d %d", &n, &m, &f);

    for (int k = 1; k <= f; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                scanf("%d", &mp[i][j][k]);
            }
        }
    }

    printf("%d", recur(1, 1, 1));
    return 0;
}

/*
2 2 2
4 9
-2 -20
7 13
1 20
*/