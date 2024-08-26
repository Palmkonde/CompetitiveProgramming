#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int N = 100005;

int n, m, q, u, v;
vector<int> h(N, 1), p(N, -1);
queue<pii> edge;

int root(int x)
{
    if (p[x] == -1)
    {
        return x;
    }
    return p[x] = root(p[x]);
}

int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        edge.push({u, v});
    }

    while (not edge.empty())
    {
        int pa = root(edge.front().first);
        int pb = root(edge.front().second);
        edge.pop();

        if (pa != pb)
        {
            if (h[pa] < h[pb])
                swap(pa, pb);

            p[pb] = pa;
            h[pa] += h[pb];
        }
    }

    scanf("%d", &q);
    while (q--)
    {
        scanf("%d%d", &u, &v);
        if (root(u) != root(v))
            printf("false\n");
        else
            printf("true\n");
    }

    return 0;
}