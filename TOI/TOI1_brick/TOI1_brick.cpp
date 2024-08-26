#include <bits/stdc++.h>
using namespace std;

int n, m;
char mp[25][25];

int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mp[i][j];
        }
    }

    int a;
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &a);

        int j;
        for (j = 0; j < n; j++)
        {
            if (mp[j][i] == 'O')
                break;
        }
        j--;

        for (; j >= 0 && a > 0; a--, j--)
        {
            mp[j][i] = '#';
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%c", mp[i][j]);
        }
        printf("\n");
    }
}