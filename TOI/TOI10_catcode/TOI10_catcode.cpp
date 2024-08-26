#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;

int k, m, n, d, tmp;
string s;
map<int, int> mp;

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> k >> m;

    for (int i = 1; i <= k; i++)
    {
        cin >> s;

        tmp = 0;
        for (int j = 0; j < m; j++)
        {
            tmp |= (s[j] - '0') * (1 << j);
        }

        mp[tmp] = i;
    }

    cin >> n;

    while (n--)
    {
        cin >> d >> s;

        bool ok = true;
        bool vis[N];

        memset(vis, 0, sizeof(vis));

        tmp = 0;
        for (int i = 0; i < m; i++)
            tmp |= ((1 << i) * (s[i] - '0'));

        for (int i = 0; i + m <= d; i++)
        {
            if (i)
            {
                tmp >>= 1;
                tmp |= ((1 << (m - 1)) * (s[i + m - 1] - '0'));
            }

            if (mp[tmp])
            {
                vis[mp[tmp]] = true;
                ok = false;
            }
        }

        if (ok)
            cout << "OK";
        else
        {
            for (int i = 0; i <= k; i++)
            {
                if (vis[i])
                    cout << i << " ";
            }
        }

        cout << "\n";
    }

    return 0;
}

/*
5 5
01001
10110
11100
10100
11111
1
20
11110110011111000010
*/