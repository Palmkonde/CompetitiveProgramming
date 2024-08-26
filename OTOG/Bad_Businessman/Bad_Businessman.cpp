#include<bits/stdc++.h>
using namespace std;

const int N = 100002;

struct pqData
{
    int dis;
    int node;
    int passport;
};

struct comp
{
    bool operator()(const pqData &a, const pqData &b)
    {
        return a.dis > b.dis;
    }
};

int n,m,s,t,k;
int dist[N][4];
bool visited[N][4];
vector<pair<int,int>> adj[N];
priority_queue<pqData, vector<pqData>, comp> pq;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k >> s >> t;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<3;j++)
        {
            dist[i][j] = INT_MAX;
        }
    }

    pq.push({0,s,0}); // dist,node, passport
    dist[s][0] = 0; //node, passport = dist;

    while(not pq.empty())
    {
        pqData now = pq.top();pq.pop();

        if(visited[now.node][now.passport]) continue;
        visited[now.node][now.passport] = true;

        //cout << now.node << " " << now.passport+1 << "\n";
        for(auto e:adj[now.node])
        {
            int next = e.first;
            int w = e.second;

            if(next == t and now.passport != 0) continue;

            else if(dist[now.node][now.passport%k]+w < dist[next][(now.passport+1)%k])
            {
                dist[next][(now.passport+1)%k] = dist[now.node][(now.passport)%k] + w;
                pq.push({dist[next][(now.passport+1)%k],next,(now.passport+1)%k});
            }
        }
    }

    /*
    for(int i=0;i<3;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout << dist[j][i] << " ";
        }
        cout << "\n";
    }*/
    
    if(k==1)
    {
        if(dist[t][0] == INT_MAX) cout << -1;
        else cout << dist[t][0];
        return 0;
    }

    if(dist[t][1] == INT_MAX) cout << -1;
    else cout << dist[t][1];

    return 0;
}

/*
3 2 3
1 2
1 3 1
3 2 2
*/