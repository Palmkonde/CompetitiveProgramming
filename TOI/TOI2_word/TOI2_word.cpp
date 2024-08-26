#include <bits/stdc++.h>
using namespace std;
int n, m, q;
int di[8][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
char mp[30][30];
bool dfs(int x, int y, int &d, int pointer, string &ori)
{
    if (x < 0 or y < 0 or x >= n or y >= m)
        return false;
    int nx = x + di[d][0];
    int ny = y + di[d][1];
    if (pointer > ori.size() - 1)
        return false;
    if (tolower(mp[x][y]) != tolower(ori[pointer]))
        return false;
    if (pointer == ori.size() - 1)
        return true;
    return dfs(nx, ny, d, pointer + 1, ori);
}
int main()
{
    // cin.tie(NULL)->sync_with_stdio(false);
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mp[i][j];
            mp[i][j] = tolower(mp[i][j]);
        }
    }
    string s;
    scanf("%d", &q);
    while (q--)
    {
        cin >> s;
        bool find = false;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                for (int k = 0; k < 8; k++)
                {
                    if (find)
                        break;
                    if (dfs(i, j, k, 0, s))
                    {
                        printf("%d %d\n", i, j);
                        find = true;
                    }
                }
                if (find)
                    break;
            }
            if (find)
                break;
        }
    }
    return 0;
}