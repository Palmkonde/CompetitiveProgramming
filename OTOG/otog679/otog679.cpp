#include <bits/stdc++.h>
#define L     \
    {         \
        0, -1 \
    }
#define R    \
    {        \
        0, 1 \
    }
#define U     \
    {         \
        -1, 0 \
    }
#define D    \
    {        \
        1, 0 \
    }
#define x first
#define y second
using namespace std;
using pii = pair<int, int>;

int n, m;
char mp[1005][1005];

unordered_map<char, vector<pii>> d = {
    {'0', {{0, 0}}},
    {'1', {U}},
    {'2', {R}},
    {'3', {D}},
    {'4', {L}},
    {'5', {U, R}},
    {'6', {U, D}},
    {'7', {U, L}},
    {'8', {D, R}},
    {'9', {L, R}},
    {'A', {L, D}},
    {'B', {L, D, R}},
    {'C', {L, U, D}},
    {'D', {L, U, R}},
    {'E', {U, R, D}},
    {'F', {U, R, D, L}}

};

queue<pair<pii, int>> q;
pii st, ed;
bool visited[1005][1005];

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mp[i][j];
        }
    }

    int a, b;
    cin >> a >> b;
    st = {a, b};
    cin >> a >> b;
    ed = {a, b};
    q.push({st, 0});

    visited[st.x][st.y] = true;

    while (not q.empty())
    {
        pii now = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (now.x == ed.x and now.y == ed.y)
        {
            cout << cnt;
            return 0;
        }

        for (auto e : d[mp[now.x][now.y]])
        {
            int nx = now.x + e.x;
            int ny = now.y + e.y;

            if (visited[nx][ny])
                continue;
            visited[nx][ny] = true;

            q.push({{nx, ny}, cnt + 1});
        }
    }

    return 0;
}