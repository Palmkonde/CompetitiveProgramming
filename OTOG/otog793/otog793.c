#include <stdio.h>
#include <stdlib.h>

int n, m, q;
char mp[1005][1005];

int main()
{
    scanf("%d%d%d", &n, &m, &q);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf(" %c", &mp[i][j]);
        }
    }

    int x, y;
    while (q--)
    {
        scanf("%d%d", &x, &y);
        printf("%c\n", mp[x][y]);
    }

    return 0;
}