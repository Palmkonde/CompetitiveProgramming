#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int N = 2505;

struct pqData
{
    int w;
    int node;

    bool operator<(const pqData other) const
    {
        return this->w > other.w;
    }
};

int n, m, u, v, w, s, t, k;
int g[N];
bool visited[N];
vector<pii> adj[N];

int main()
{
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &u, &v, &w);
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    scanf("%d %d %d", &s, &t, &k);

    fill(g, g + (n + 1), INT_MAX);

    priority_queue<pqData> pq;

    g[s] = 0;
    pq.push({0, s}); // w node
    while (not pq.empty())
    {
        pqData now = pq.top();
        pq.pop();

        if (visited[now.node])
            continue;
        visited[now.node] = true;

        for (auto e : adj[now.node])
        {
            int nx = e.first;
            int w = e.second;
            double temp = (double)(((double)(k)) / ((double)(w - 1)));
            int guide = ceil(temp);

            if (g[nx] > guide)
            {
                if (now.w > guide)
                {
                    g[nx] = now.w;
                    pq.push({now.w, nx});
                }
                else
                {
                    g[nx] = guide;
                    pq.push({guide, nx});
                }
            }
        }
    }

    printf("%d", g[t]);

    return 0;
}
/*
7 10
1 2 30
1 3 15
1 4 10
2 4 25
2 5 60
3 4 40
4 7 35
3 6 20
5 7 20
7 6 30
1 5 8
*/