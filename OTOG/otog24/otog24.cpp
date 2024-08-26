#include <bits/stdc++.h>
using namespace std;

int n, x, y, c;
bool visited[1000][1000];
int di[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> n >> x >> y >> c;

    queue<pair<int, int>> q;

    q.push({x, y});
    visited[x][y] = 1;

    int cnt = 1;

    for (int i = 0; i <= 1000; i++)
    {
        int qs = q.size();
        while (qs--)
        {
            int t1 = q.front().first;
            int t2 = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nx = t1 + di[i][0];
                int ny = t2 + di[i][1];

                if (visited[nx][ny] or nx < 0 or ny < 0 or nx >= n or ny >= n)
                    continue;

                visited[nx][ny] = 1;
                cnt++;
                q.push({nx, ny});
            }
        }

        if (cnt >= c)
        {
            cout << i;
            return 0;
        }
    }

    return 0;
}