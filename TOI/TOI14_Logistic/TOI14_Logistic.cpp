#include <bits/stdc++.h>
using namespace std;

const int N = 2002;
const int INF = 1e9;

struct node
{
    int next;
    int weight;
};

struct car
{
    int start;
    int end;
    int cap;
};

struct pqData
{
    int cost;
    int node;
    int remain;
    int ticket;

    bool operator<(const pqData &other) const
    {
        return this->cost > other.cost;
    }
};

int n, a, b, c, m;
int prize[N];
int cost[N][103][2]; // node , remain, ticket
//               ^ 0 ยังไม่ใช้ , 1 ใช้แล้ว

int visited[N][103][2];
vector<node> adj[N];
car st;

priority_queue<pqData> pq;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> prize[i];

    cin >> a >> b >> c;
    st = {a, b, c};

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= st.cap; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                cost[i][j][k] = INF;
            }
        }
    }

    //ถังเปล่า ไม่มีน้ำมัน
    cost[st.start][0][1] = 0;
    pq.push({0, st.start, 0, 1}); // cost (for cmp) | node remain ticket

    while (not pq.empty())
    {
        pqData now = pq.top();
        pq.pop();

        if (now.cost > cost[now.node][now.remain][now.ticket])
            continue;

        if (now.ticket == 1)
        {
            if (now.cost < cost[now.node][st.cap][0])
            {
                cost[now.node][st.cap][0] = now.cost;
                pq.push({cost[now.node][st.cap][0], now.node, st.cap, 0});
            }
        }

        //เติมไม่เต็มถีง
        if (now.remain < st.cap)
        {
            if (now.cost + prize[now.node] < cost[now.node][now.remain + 1][now.ticket])
            {
                cost[now.node][now.remain + 1][now.ticket] = now.cost + prize[now.node];
                pq.push({cost[now.node][now.remain + 1][now.ticket], now.node, now.remain + 1, now.ticket});
            }
        }

        for (auto child : adj[now.node])
        {
            if (now.remain - child.weight >= 0)
            {
                int fuelleft = now.remain - child.weight;
                if (now.cost < cost[child.next][fuelleft][now.ticket])
                {
                    cost[child.next][fuelleft][now.ticket] = now.cost;
                    pq.push({cost[child.next][fuelleft][now.ticket], child.next, fuelleft, now.ticket});
                }
            }
        }
    }

    cout << cost[st.end][st.cap][0];
    return 0;
}
/*
4
7 1 8 10
1 4 100
5
1 2 60
1 3 50
1 4 90
2 4 30
3 4 20

5
10 1 3 10 30
1 4 20
4
1 2 1
1 5 5
4 5 20
3 4 2
*/