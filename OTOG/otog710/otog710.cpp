#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int N = 55;

int n, m;
char mp[N][N];
pii st, ed;
queue<tuple<pii, vector<pii>>> q;
int di[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
bool visited[N][N];

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mp[i][j];

            if (mp[i][j] == 'A')
            {
                st = {i, j};
            }
            else if (mp[i][j] == 'B')
            {
                ed = {i, j};
            }
        }
    }

    mp[st.first][st.second] = 'O';
    mp[ed.first][ed.second] = 'O';
    q.push({st, {{st.first, st.second}}});
    visited[st.first][st.second] = true;

    while (not q.empty())
    {
        pii now;
        vector<pii> path;

        tie(now, path) = q.front();
        q.pop();

        if (now.first == ed.first and now.second == ed.second)
        {
            for (auto e : path)
            {
                cout << "\n";
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < m; j++)
                    {
                        if (i == e.first and j == e.second)
                        {
                            cout << "A ";
                        }
                        else
                            cout << mp[i][j] << " ";
                    }
                    cout << "\n";
                }
            }

            return 0;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = now.first + di[i][0];
            int ny = now.second + di[i][1];

            if (visited[nx][ny] or mp[nx][ny] == '#')
                continue;
            visited[nx][ny] = true;

            vector<pii> temp(path.begin(), path.end());
            temp.push_back({nx, ny});
            q.push({{nx, ny}, temp});
        }
    }

    return 0;
}