#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int N = 505;

struct pqData
{
    int w;
    int x;
    int y;
    int state;

    bool operator<(const pqData &other) const
    {
        return this->w > other.w;
    }
};

int n, m;
char mp[N][N];
pii st, ed;
map<char, int> permit = {
    {'P', 0},
    {'B', 1},
    {'J', 2}};

int dist[N][N][10];
bool visited[N][N][10];
int di[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mp[i][j];
            if (mp[i][j] == 'S')
            {
                st = {i, j};
            }
            else if (mp[i][j] == 'E')
            {
                ed = {i, j};
            }
        }
    }

    // init
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < 8; k++)
            {
                dist[i][j][k] = INT_MAX;
            }
        }
    }

    priority_queue<pqData> pq;
    dist[st.first][st.second][0] = 0;

    pq.push({0, st.first, st.second, 0}); // w, x, y, state
    while (not pq.empty())
    {
        pqData now = pq.top();
        pq.pop();

        if (visited[now.x][now.y][now.state])
            continue;
        visited[now.x][now.y][now.state] = true;

        // cout << now.x << " " << now.y << " " << now.w << " " << now.state << "\n";

        for (int i = 0; i < 4; i++)
        {
            int nx = now.x + di[i][0];
            int ny = now.y + di[i][1];

            if (mp[nx][ny] == '#' or nx >= n or ny >= m or nx < 0 or ny < 0)
                continue;

            if (mp[nx][ny] == 'J' or mp[nx][ny] == 'B' or mp[nx][ny] == 'P')
            {
                //เจอ แต่ไม่มีใบอณุญาติ
                if ((now.state & (1 << permit[mp[nx][ny]])) == 0)
                {
                    continue;
                }

                //มีใบ
                else
                {
                    if (dist[nx][ny][now.state] > dist[now.x][now.y][now.state] + 1)
                    {
                        dist[nx][ny][now.state] = dist[now.x][now.y][now.state] + 1;
                        pq.push({dist[nx][ny][now.state], nx, ny, now.state});
                    }
                }
            }

            //ไปขอใบอณุญาติ
            if (mp[nx][ny] == 'j' or mp[nx][ny] == 'b' or mp[nx][ny] == 'p')
            {
                // ไม่มีใบอยู่แล้ว
                int ns = now.state;
                if ((now.state & (1 << (permit[toupper(mp[nx][ny])]))) == 0)
                {
                    ns |= (1 << (permit[toupper(mp[nx][ny])]));
                }

                // เดินทาง
                if (dist[nx][ny][ns] > dist[now.x][now.y][now.state] + 1)
                {
                    dist[nx][ny][ns] = dist[now.x][now.y][now.state] + 1;
                    pq.push({dist[nx][ny][ns], nx, ny, ns});
                }
            }

            //เจอทางปกติ
            if (dist[nx][ny][now.state] > dist[now.x][now.y][now.state] + 1)
            {
                dist[nx][ny][now.state] = dist[now.x][now.y][now.state] + 1;
                pq.push({dist[nx][ny][now.state], nx, ny, now.state});
            }
        }
    }

    int mn = INT_MAX;
    for (int i = 0; i <= 7; i++)
    {
        mn = min(mn, dist[ed.first][ed.second][i]);
    }

    if (mn == INT_MAX)
    {
        cout << "-1";
    }

    else
    {
        cout << mn;
    }

    return 0;
}