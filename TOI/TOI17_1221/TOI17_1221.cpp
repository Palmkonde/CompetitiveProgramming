#include <bits/stdc++.h>
using namespace std;

const int N = 505;

int n, m, q, a, b, w;
int c[N], dist[N][N], amount[N][N];

int main()
{
    scanf("%d%d%d", &n, &m, &q);

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &c[i]);
    }

    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &a, &b, &w);

        dist[a][b] = w;
        dist[b][a] = w;
        amount[a][b] = 2;
        amount[b][a] = 2;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (!dist[i][j])
            {
                dist[i][j] = c[i] + c[j];
                amount[i][j] = 2;
            }
            if (i == j)
            {
                dist[i][j] = 0;
                amount[i][j] = 1;
            }
        }
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    amount[i][j] = amount[i][k] + amount[k][j];
                }
            }
        }
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         printf("%d ", amount[i][j]);
    //     }
    //     printf("\n");
    // }

    while (q--)
    {
        scanf("%d%d", &a, &b);
        printf("%d %d\n", dist[a][b], amount[a][b]);
    }

    return 0;
}