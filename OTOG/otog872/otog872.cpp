#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int N = 1005;
const int K = 100005;

int q, n, m, k, s, u, v;

void slove()
{
    bool v[N][K];
    vector<pii> adj[N];

    scanf("%d %d %d %d", &n, &m, &k, &s);

    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &u, &v);
        adj[u].push_back({v, w});
    }
}

int main()
{
    scanf("%d", &q);

    while (q--)
    {
        slove();
    }

    return 0;
}