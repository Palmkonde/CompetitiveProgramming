#include <bits/stdc++.h>
using namespace std;
using TUPLE = tuple<int, int, int>;

const int N = 50005;
const int M = 250005;

int n, m, g, tim[N], dist[N], tl = INT_MAX;
char a[105], b[105];
unordered_map<string, int> k; // ดาว , index;
vector<pair<int, int>> adj[N];
bool visited[N];

unordered_map<int, string> debug;

int main()
{
    scanf("%d %d", &n, &m);
    scanf("%s %s %d", &a, &b, &g);

    for (int i = 0; i < n; i++)
    {
        char temp[105];
        int t;

        scanf("%s %d", &temp, &t);

        k[temp] = i;
        tim[i] = t;
        dist[i] = INT_MAX;

        debug[i] = temp;
    }

    for (int i = 0; i < m; i++)
    {
        char u[105], v[105];
        int w;

        scanf("%s %s %d", &u, &v, &w);

        adj[k[u]].push_back({k[v], w});
        adj[k[v]].push_back({k[u], w});
    }

    priority_queue<TUPLE, vector<TUPLE>, greater<TUPLE>> pq; // time w node

    dist[k[a]] = 0;
    pq.push(make_tuple(0, 0, k[a]));

    while (not pq.empty())
    {
        int nowNode, nowtime;
        tie(nowtime, std::ignore, nowNode) = pq.top();
        pq.pop();

        if (nowNode == k[b])
        {
            printf("%d %d", nowtime, dist[k[b]]);
            return 0;
        }

        for (auto e : adj[nowNode])
        {
            int nx = e.first;
            int w = e.second;

            // เวลาที่ใช้อยู่ตอนนี้ มากกว่า เวลาที่เคยไปถึงดาวเป้าหมาย ที่น้อยที่สุด
            if (nowtime > tl)
                continue;

            //เชื้อเพลงไม่พอ
            if (dist[nowNode] + w > g)
                continue;

            if (dist[nx] > (dist[nowNode] + w))
            {
                dist[nx] = dist[nowNode] + w;
                pq.push(make_tuple(max(tim[nx], nowtime), dist[nx], nx));
            }
        }
    }

    return 0;
}