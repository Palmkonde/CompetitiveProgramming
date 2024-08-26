#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int N = 105;

vector<pii> mp[N][N];
char tmp;
bool vis[N][N];
int n, m;

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> tmp;

            if (tmp == 'R' or tmp == 'B')
            {
                mp[i][j].push_back({i, j + 1});
                mp[i][j + 1].push_back({i, j});
            }
            if (tmp == 'D' or tmp == 'B')
            {
                mp[i][j].push_back({i + 1, j});
                mp[i + 1][j].push_back({i, j});
            }
        }
    }

    queue<pii> q;

    q.push({1, 1});
    int t = 1;
    while (not q.empty())
    {
        int qs = q.size();
        for (int i = 0; i < qs; i++)
        {
            int nowx = q.front().first;
            int nowy = q.front().second;
            q.pop();
            if (vis[nowx][nowy])
            {
                cout << t << "\n";
                cout << nowx << " " << nowy;
                return 0;
            }

            vis[nowx][nowy] = 1;
            for (auto e : mp[nowx][nowy])
            {
                if (e.first < 1 or e.second < 1 or e.first > n or e.second > m)
                    continue;
                if (vis[e.first][e.second])
                    continue;

                q.push(e);
            }
        }
        t++;
    }

    return 0;
}