#include <bits/stdc++.h>
using namespace std;

const int N = 30;

int n;
int mp[N][N];

struct pqData
{
    int predic;
    int used;
    int row = 0;
    int now = 0;
    bool operator<(const pqData &other) const
    {
        return this->predic > other.predic;
    }
};

int predic(int bit, int ss)
{
    int res = 0;
    for (int i = ss; i < n; i++)
    {
        int mn = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            if (!(bit & (1 << j)))
            {
                if (mp[i][j] < mn)
                {
                    mn = mp[i][j];
                }
            }
        }
        res += mn;
    }

    return res;
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mp[i][j];
        }
    }

    priority_queue<pqData> pq; // perdict = now + function , set<int> , row , now

    int v = 0;
    for (int i = 0; i < n; i++)
    {
        int u = predic(v | (1 << i), 1) + mp[0][i];
        pq.push({u, v | (1 << i), 0, mp[0][i]});
    }

    while (not pq.empty())
    {
        pqData t = pq.top();
        pq.pop();

        // cout << t.predic << " " << t.now << "\n";
        if (t.row == n - 1)
        {
            cout << t.now;
            return 0;
        }

        int tt = t.used;
        for (int i = 0; i < n; i++)
        {
            if (t.used & (1 << i))
                continue;

            int nx = predic(tt | (1 << i), t.row + 2) + mp[t.row + 1][i] + t.now;

            pq.push({nx, tt | (1 << i), t.row + 1, t.now + mp[t.row + 1][i]});
        }
    }

    return 0;
}
/*
4
2 4 7 8
5 6 4 1
8 9 2 3
7 6 3 4

4
18 12 15 20
15 10 14 25
10 12 17 23
14 18 8 40
*/