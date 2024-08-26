#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using TUPLE = tuple<pii, int, pii>; // pos, turn, lastdir

const int N = 2505;

char mp[N][N];
int ans[N][N];
int n;
pii st;
pii dir[] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0}};

queue<TUPLE> q;

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mp[i][j];
            if (mp[i][j] == 'K')
            {
                st = {i, j};
            }
            ans[i][j] = INT_MAX;
        }
    }

    for (auto d : dir)
    {
        q.push({st, 0, d});
    }

    while (not q.empty())
    {
        pii lastdi, pos;
        int turn;

        tie(pos, turn, lastdi) = q.front();
        q.pop();

        int x = pos.first;
        int y = pos.second;

        for (auto d : dir)
        {
            int nx = x + d.first;
            int ny = y + d.second;
            int nTurn = turn + (lastdi != d);
            if (nx < 0 or ny < 0 or ny >= n or nx >= n or mp[nx][ny] != '.' or nTurn > ans[nx][ny])
            {
                continue;
            }

            q.push({{nx, ny}, nTurn, d});
            ans[nx][ny] = nTurn;
        }
    }

    int mx = 0, cnt = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mp[i][j] == '.' and ans[i][j] != INT_MAX)
            {
                if (ans[i][j] > mx)
                {
                    mx = ans[i][j];
                    cnt = 1;
                }
                else if (ans[i][j] == mx)
                {
                    cnt++;
                }
            }
        }
    }

    cout << mx << "\n"
         << cnt;

    return 0;
}