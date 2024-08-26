#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using tii = tuple<int, int, int, int>;

const int N = 55;

int n, m;
char mp[N][N], buff[N];
int di[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void solve()
{
    pii st, tar;
    for (int i = 0; i < n; i++)
    {
        scanf("%s", buff);
        for (int j = 0; j < m; j++)
        {
            mp[i][j] = buff[j];

            if (buff[j] == 'A')
            {
                st = {i, j};
            }

            if (buff[j] == 'B')
            {
                tar = {i, j};
            }
        }
    }

    priority_queue<tii, vector<tii>, greater<tii>> pq;
    pq.push({0, 0, st.first, st.second});

    while (not pq.empty())
    {
        int t, d, x, y;
        tie(t, d, x, y) = pq.top();
        pq.pop();

        if (make_pair(x, y) == tar)
        {
            printf("%d %d\n", t, d);
            return;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + di[i][0];
            int ny = y + di[i][1];

            if (nx < 0 or ny < 0 or nx >= n or ny >= m)
                continue;
            if (mp[nx][ny] == '#')
                continue;

            if (mp[nx][ny] == 't')
                pq.push({t + 1, d + 1, nx, ny});

            else
                pq.push({t, d + 1, nx, ny});
            mp[nx][ny] = '#';
        }
    }

    printf("-1\n");
}

int main()
{
    while (scanf("%d%d", &n, &m) != EOF)
        solve();
}