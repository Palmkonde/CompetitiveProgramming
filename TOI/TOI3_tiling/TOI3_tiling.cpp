#include <bits/stdc++.h>
using namespace std;

int n;
bool v[20][20];
int mp[20][20];

bool check(int x, int y)
{
    if (v[x][y])
        return false;

    if (mp[x][y] == mp[x + 1][y] and mp[x][y] == mp[x][y + 1])
    {
        v[x][y] = v[x + 1][y] = v[x][y + 1] = true;
        return true;
    }

    if (mp[x][y] == mp[x - 1][y] and mp[x][y] == mp[x - 1][y + 1])
    {
        v[x][y] = v[x - 1][y] = v[x - 1][y + 1] = true;
        return true;
    }

    if (mp[x][y] == mp[x][y - 1] and mp[x][y] == mp[x + 1][y - 1])
    {
        v[x][y] = v[x][y - 1] = v[x + 1][y - 1] = true;
        return true;
    }

    if (mp[x][y] == mp[x][y - 1] and mp[x][y] == mp[x - 1][y])
    {
        v[x][y] = v[x][y - 1] = v[x - 1][y] = true;
        return true;
    }

    if (mp[x][y] == mp[x][y + 1] and mp[x][y] == mp[x - 1][y + 1])
    {
        v[x][y] = v[x][y + 1] = v[x - 1][y + 1] = true;
        return true;
    }

    if (mp[x][y] == mp[x + 1][y - 1] and mp[x][y] == mp[x + 1][y])
    {
        v[x][y] = v[x + 1][y - 1] = v[x + 1][y] = true;
        return true;
    }

    if (mp[x][y] == mp[x][y + 1] and mp[x][y] == mp[x + 1][y + 1])
    {
        v[x][y] = v[x][y + 1] = v[x + 1][y + 1] = true;
        return true;
    }

    if (mp[x][y] == mp[x][y - 1] and mp[x][y] == mp[x + 1][y])
    {
        v[x][y] = v[x][y - 1] = v[x + 1][y] = true;
        return true;
    }

    if (mp[x][y] == mp[x - 1][y - 1] and mp[x][y] == mp[x - 1][y])
    {
        v[x][y] = v[x - 1][y - 1] = v[x - 1][y] = true;
        return true;
    }

    if (mp[x][y] == mp[x + 1][y + 1] and mp[x][y] == mp[x + 1][y])
    {
        v[x][y] = v[x + 1][y + 1] = v[x + 1][y] = true;
        return true;
    }

    if (mp[x][y] == mp[x - 1][y] and mp[x][y] == mp[x][y + 1])
    {
        v[x][y] = v[x - 1][y] = v[x][y + 1] = true;
        return true;
    }

    if (mp[x][y] == mp[x][y - 1] and mp[x][y] == mp[x - 1][y - 1])
    {
        v[x][y] = v[x][y - 1] = v[x - 1][y - 1] = true;
        return true;
    }
}

int main()
{
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &mp[i][j]);
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (v[i][j])
                continue;
            cnt += check(i, j);
        }
    }

    printf("%d", cnt);

    return 0;
}