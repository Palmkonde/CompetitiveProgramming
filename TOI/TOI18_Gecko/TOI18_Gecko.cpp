#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int N = 20005;

struct pqData
{
    int w, u;

    bool operator<(const pqData &other) const
    {
        return this->w > other.w;
    }
};

int n, m, k, p;
int g[N], parent[N], ing[N];
int dist[N];
vector<pii> adj[N];
priority_queue<pqData> pq;
queue<int> q;
vector<pii> ans;

int main()
{
    scanf("%d %d %d %d", &n, &m, &k, &p);

    memset(parent, -1, sizeof(parent));

    for (int i = 0; i < k; i++)
    {
        scanf("%d", &g[i]);
    }

    int u, v, w;
    for (int i = 0; i < m; i++)
    {

        scanf("%d%d%d", &u, &v, &w);
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // djikstra จากจุด p เพื่อหาว่า shortest path จาก p ไป g แต่ละตัวเป็นเท่าไหร่ --------------------------------------------
    fill(dist, dist + n, INT_MAX);
    dist[p] = 0;
    pq.push({dist[p], p});

    while (not pq.empty())
    {
        w = pq.top().w;
        int now = pq.top().u;
        pq.pop();

        if (dist[now] < w)
            continue;

        for (auto e : adj[now])
        {
            int nx = e.first;
            int nw = e.second;

            if (dist[nx] > dist[now] + nw)
            {
                dist[nx] = dist[now] + nw;
                pq.push({dist[nx], nx});
                parent[nx] = now;
            }
        }
    }

    for (int i = 0; i < k; i++)
    {
        printf("%d ", dist[g[i]]);
    }
    printf("\n");
    //----------------------------------------------------------------------------

    // จาก shorest path เรามาทำเป็น indegree เพื่อที่จะ topological sort
    // โดย path ได้มาจากบรรทัด ที่ 68
    for (int i = 0; i < n; i++)
    {
        if (parent[i] != -1)
        {
            ing[parent[i]]++;
        }
    }

    int l = 0; // ไม้ที่เหลือจะเท่าจำนวน indegree ของแต่ละตัวอัน
    for (int i = 0; i < n; i++)
    {
        if (ing[i] == 0)
        {
            q.push(i);
        }
        l += ing[i];
    }

    // ทำการ topological
    while (not q.empty())
    {
        int now = q.front();
        q.pop();
        int nx = parent[now];

        if (nx == -1)
            break;

        if (ing[now] == 0)
        {
            ans.push_back({min(now, nx), max(now, nx)});
        }

        ing[nx]--;
        if (ing[nx] == 0)
        {
            q.push(nx);
        }
    }

    printf("%d\n", l);
    for (auto e : ans)
    {
        printf("%d %d\n", e.first, e.second);
    }

    return 0;
}