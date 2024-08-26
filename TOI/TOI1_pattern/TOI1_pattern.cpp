#include <bits/stdc++.h>
using namespace std;
using tiii = tuple<int, int, int>;
int n, p, q, r;
int mp[50000][75];
vector<tiii> v;
int main()
{
    scanf("%d", &n);
    int mx = -1;
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &p, &q, &r);
        mx = max(p, mx);
        for (int j = q; j <= min(71, q + r - 1); j++)
        {
            mp[p][j] = 1;
        }
    }
    for (int i = 1; i <= mx; i++)
    {
        for (int j = 1; j <= 70; j++)
        {
            if (mp[i][j])
                printf("x");
            else
                printf("o");
        }
        printf("\n");
    }
    return 0;
}