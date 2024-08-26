#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int N = 12350;

int n, x, y;
int dist[N];
bool inMst[N];
pii adj[N];
priority_queue<pii> pq;

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &x, &y);
        adj[i] = {x, y};
    }

    fill(dist, dist + n + 1, INT_MIN);

    dist[0] = 0;
    pq.push({dist[0], 0});

    while (not pq.empty())
    {
        int now = pq.top().second;
        pq.pop();
        if (inMst[now])
            continue;
        inMst[now] = true;

        for (int i = 0; i < n; i++)
        {
            if (inMst[i])
                continue;

            int w = max(abs(adj[i].first - adj[now].first), abs(adj[i].second - adj[now].second));

            if (dist[i] < w && !inMst[i])
            {
                dist[i] = w;
                pq.push({dist[i], i});
            }
        }
    }

    int cost = 0;
    for (int i = 0; i < n; i++)
    {
        cost += dist[i];
    }

    printf("%d", cost);

    return 0;
}