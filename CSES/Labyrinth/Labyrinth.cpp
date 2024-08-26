#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int N = 1005;

int n, m;
int di[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int prevstep[N][N];
char dd[4] = {'D', 'R', 'U', 'L'};
char buff[N], mp[N][N];
pii st, ed;
queue<pii> q;

int main()
{
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++)
    {
        scanf("%s", buff);
        for (int j = 0; j < m; j++)
        {
            mp[i][j] = buff[j];

            if (mp[i][j] == 'A')
                st = {i, j};

            else if (mp[i][j] == 'B')
                ed = {i, j};
        }
    }

    q.push(st);

    pii now;
    while (not q.empty())
    {
        now = q.front();
        q.pop();

        if (now == ed)
            break;

        for (int i = 0; i < 4; i++)
        {
            int nx = now.first + di[i][0];
            int ny = now.second + di[i][1];

            if (nx < 0 or ny < 0 or nx >= n or ny >= m)
                continue;

            if (mp[nx][ny] == '#')
                continue;

            mp[nx][ny] = '#';
            prevstep[nx][ny] = i;
            q.push({nx, ny});
        }
    }

    int cnt = 0;
    vector<char> p;
    if (now == ed)
    {
        printf("YES\n");

        while (now != st)
        {
            int a = prevstep[now.first][now.second];

            p.push_back(dd[a]);

            now.first -= di[a][0];
            now.second -= di[a][1];
        }

        printf("%d\n", p.size());
        reverse(p.begin(), p.end());

        for (auto e : p)
        {
            printf("%c", e);
        }
        return 0;
    }
    else
        printf("NO");

    return 0;
}