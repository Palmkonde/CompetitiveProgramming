#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
const int Q = 1000005;

int mp[N][N];
int64_t row[N], col[N];
int n, m, q;

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> n >> m >> q;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> mp[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            row[i] += mp[i][j];
        }
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            col[i] += mp[j][i];
        }
    }

    while (q--)
    {
        int a, b;
        cin >> a >> b;

        cout << (row[a] + col[b]) - mp[a][b] << "\n";
    }

    return 0;
}