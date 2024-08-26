#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int N = 105;

int n, q;
int dp[N][N];
vector<pii> adj[N];

int dfs(int u, int p)
{
    int bp = 1; // กระเป๋าเริ่มต้นของแต่ละ Node มี 1
    for (auto e : adj[u])
    {
        int nx = e.first;
        int nw = e.second;

        if (nx == p)
            continue;

        bp += dfs(nx, u); // travel จนถึง leaf และรวมว่ามี กระเป๋ามีความจุเท่าไหร่

        for (int i = bp; i > 0; i--) // กระเป๋าของ parent ที่มีขนาด i
        {
            for (int j = 1; i - j > 0; j++) // กระเป๋าของ child ที่มีขนาด j
            {
                // เมื่อ child ใช้ไป j กระเป๋าแสดงว่า
                // parent ต้องใช้ i-j จะเป๋าถึงจะได้ i กระเป๋าพอดี
                dp[u][i] = max({dp[u][i], dp[u][i - j] + dp[nx][j] + nw});
            }
        }
    }

    return bp;
}

int main()
{
    scanf("%d%d", &n, &q);

    int u, v, w;
    for (int i = 1; i < n; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dfs(1, -1);
    printf("%d", dp[1][q + 1]);

    return 0;
}

/*
เราจะเริ่มทำ 01-knapsack จาก leaf แล้วค่อยๆรวมกันจนมาถึง root
เพราะคำตอบอาจจะอยู่ใน subtree อันไหนก็ได้ที่เราไม่รู้

ให้ dp[i][j] โดยที่ i คือ Node ที่ i , j คือจำนวนโหนดที่จะเก็บ (กระเป๋า)
*/