#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int r, c;
int mp[N][N], tmp[N][N];
int di[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main()
{
    scanf("%d%d", &r, &c);

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &mp[i][j]);
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (mp[i][j] != 0)
            {
                tmp[i][j] = mp[i][j];
                continue;
            }

            int cnt = 0, s = 0;
            for (int k = 0; k < 4; k++)
            {
                int nx = i + di[k][0];
                int ny = j + di[k][1];

                if (nx < 0 or ny < 0 or nx >= r or ny >= c)
                    continue;

                if (mp[nx][ny] == 0)
                    continue;

                cnt++;
                s += mp[nx][ny];
            }

            if (cnt == 0)
            {
                tmp[i][j] = 0;
                continue;
            }
            tmp[i][j] = s / cnt;
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", tmp[i][j]);
        }
        printf("\n");
    }

    return 0;
}