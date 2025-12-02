#include <bits/stdc++.h>
using namespace std;
using tiii = tuple<int, int, int>;

const int N = 1005;

int n, m, cost, a, b, c;
vector<tiii> edges;
int q[N], parent[N];

int root(int x)
{
    if (parent[x] == -1)
        return x;

    return parent[x] = root(parent[x]);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &q[i]);
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        edges.push_back({a, b, c});
    }

    fill(parent, parent + N, -1);
    sort(edges.begin(), edges.end(), [](tiii &a, tiii &b)
         { return get<2>(a) < get<2>(b); });

    for (auto &edge : edges)
    {
        tie(a, b, c) = edge;

        if (parent[b] != -1)
            continue;
        
        int pa = root(a);
        int pb = root(b);

        if (pa != pb)
        {
            parent[pb] = pa;
            cost += c;

            // for(int i=1; i<=n; i++) printf("%d ", parent[i]);
            // printf("  cost:%d\n", cost);

        }
    }

    bool f=false;
    for(int i=1, cnt=0; i<=n; i++) {
        if(parent[i] == -1) cnt++;
        if(cnt==2) f=true;
    }

    printf("%d", (f) ? -1 : cost);

    return 0;
}