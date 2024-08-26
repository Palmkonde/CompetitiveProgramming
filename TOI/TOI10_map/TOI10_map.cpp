#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int N = 205;

int n, m;
int mp[405][405];
char c;
vector<pair<int, pii>> adj[N * N];
queue<pair<int, pii>> q;

void dfs(int num, int x, int y)
{
    // printf("%d %d %d\n", num, x, y);
    for (auto e : adj[num])
    {
        int nx = x + e.second.first;
        int ny = y + e.second.second;

        if (mp[nx][ny] != -1)
            continue;

        mp[nx][ny] = e.first;
        dfs(e.first, nx, ny);
    }
}

void bfs(int num, int x, int y)
{
    q.push({num, {x, y}});

    while (not q.empty())
    {
        int num = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();

        for (auto e : adj[num])
        {
            int nx = x + e.second.first;
            int ny = y + e.second.second;

            if (mp[nx][ny] != -1)
                continue;

            mp[nx][ny] = e.first;

            q.push({mp[nx][ny], {nx, ny}});
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);

    memset(mp, -1, sizeof(mp));

    int a, b;
    for (int i = 1; i < (m * n); i++)
    {
        scanf("%d %c %d", &a, &c, &b);

        if (c == 'U')
        {
            adj[a].push_back({b, {1, 0}});
            adj[b].push_back({a, {-1, 0}});
        }
        else
        {
            adj[a].push_back({b, {0, 1}});
            adj[b].push_back({a, {0, -1}});
        }
    }

    mp[200][200] = 0;
    // dfs(0, 200, 200);
    bfs(0, 200, 200);

    int sx = 0, sy = 0;
    bool fg = false;
    for (int i = 0; i < 405; i++)
    {
        for (int j = 0; j < 405; j++)
        {
            if (mp[i][j] != -1)
            {
                sx = i;
                sy = j;
                fg = true;
                break;
            }
        }
        if (fg)
            break;
    }

    for (int i = sx; i < sx + n; i++)
    {
        for (int j = sy; j < sy + m; j++)
        {
            printf("%d ", mp[i][j]);
        }
        printf("\n");
    }

    return 0;
}
