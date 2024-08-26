#include <bits/stdc++.h>
using namespace std;
using TUPLE = tuple<int, vector<int>, int, int>;

int mp[20][20];
int n, m;
int st;

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> n >> m;
    cin >> st;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> mp[i][j];
        }
    }

    priority_queue<TUPLE, vector<TUPLE>, greater<TUPLE>> pq;

    pq.push({mp[st][1],
             {mp[st][1]},
             st,
             1});

    while (not pq.empty())
    {
        int sum, row, col;
        vector<int> temp;

        tie(sum, temp, row, col) = pq.top();
        pq.pop();

        if (col == m)
        {
            cout << sum << "\n";
            for (auto e : temp)
            {
                cout << e << " ";
            }
            return 0;
        }

        for (int i = -1; i <= 1; i++)
        {
            int nr = row + i;
            int nc = col + 1;

            if (nr < 1 or nr > n or nc > m)
                continue;

            vector<int> path(temp);

            path.push_back(mp[nr][nc]);

            pq.push({sum + mp[nr][nc], path, nr, nc});
        }
    }

    return 0;
}