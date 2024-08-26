#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int t, n, m, a, b;
int parent[N], color[N];
queue<int> q;

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> t;
    while (t--)
    {
        cin >> n >> m;

        vector<int> adj[N];
        memset(color, -1, sizeof(color));

        while (not q.empty())
            q.pop();

        for (int i = 0; i < m; i++)
        {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        int fg = 0;
        q.push(0);
        for (int i = 0; i < n; i++)
        {
            q.push(i);
            if (color[i] == -1)
                color[i] = 1;

            while (not q.empty())
            {
                int now = q.front();
                q.pop();

                for (auto e : adj[now])
                {
                    if (color[e] != -1)
                    {
                        if (color[e] == color[now])
                        {
                            fg = 1;
                        }

                        continue;
                    }

                    color[e] = not color[now];
                    q.push(e);
                }
            }
        }

        if (fg)
        {
            cout << "Gay found!\n";
        }

        else if (!fg)
        {
            cout << "Gay not found!\n";
        }
    }

    return 0;
}

/*
2
3 3
0 1
1 2
0 2
4 2
0 1
2 3
*/