#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int q;

int main()
{
    scanf("%d", &q);

    while (q--)
    {
        bool fg = 1;
        vector<int> adj[N];
        queue<int> q;
        char color[N];
        int n, m;

        memset(color, -1, sizeof(color));

        scanf("%d%d", &n, &m);

        int a, b;
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d", &a, &b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        q.push(1);
        color[1] = 0;

        while (not q.empty())
        {
            int now = q.front();
            int c = color[now];
            q.pop();

            for (auto e : adj[now])
            {
                if (color[e] != -1)
                {
                    if (color[now] == color[e])
                    {
                        fg = 0;
                    }
                }

                if (color[e] == -1)
                {
                    color[e] = !c;
                    q.push(e);
                }
            }
        }

        if (fg)
        {
            printf("yes\n");
        }
        else
            printf("no\n");
    }

    return 0;
}