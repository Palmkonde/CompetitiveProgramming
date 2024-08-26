#include <bits/stdc++.h>
using namespace std;

int s, n, m;
int mp[25][25];

int main()
{
    scanf("%d%d%d", &n, &m, &s);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &mp[i][j]);
        }
    }

    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        ans++;
        int a = 0;
        int mx = -1;

        for (int j = 0; j < n; j++)
        {
            mp[j][i] += a;

            a += s;
            if (j)
                ans += (mp[j][i] > mx);

            mx = max(mp[j][i], mx);
        }
    }

    printf("%d", ans);

    return 0;
}