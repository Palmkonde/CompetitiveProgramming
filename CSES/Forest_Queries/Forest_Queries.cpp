#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, q;
int mp[N][N];
char buff[N];

int main()
{
    scanf("%d%d", &n, &q);

    for (int i = 1; i <= n; i++)
    {
        scanf("%s", buff);
        for (int j = 1, idx = 0; j <= n; j++, idx++)
        {
            mp[i][j] = (buff[idx] == '*');
        }
    }

    // calculate prefixsum
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            mp[i][j] = mp[i][j] + mp[i - 1][j] + mp[i][j - 1] - mp[i - 1][j - 1];
        }
    }

    int a, b, A, B;
    while (q--)
    {
        scanf("%d %d %d %d", &a, &b, &A, &B);

        int ans = mp[A][B] - mp[a - 1][B] - mp[A][b - 1] + mp[a - 1][b - 1];

        printf("%d\n", ans);
    }

    return 0;
}

// https://usaco.guide/silver/more-prefix-sums?lang=cpp
//  การทำ prefix 2D