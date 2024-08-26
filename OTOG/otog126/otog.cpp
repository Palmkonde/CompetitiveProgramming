#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

int n,m,k;
char tempc,buff[10005];
vector<pii> adj[2005];
pii st,ed;
pii temp[2005];
bool visited[2005];
int dist[2005];

int main()
{
    scanf("%d %d %d",&n,&m,&k);
    int cnt = 1;
    for(int i=0;i<n;i++)
    {
        scanf("%s",&buff);
        for(int j=0;j<m;j++)
        {
            tempc = buff[j];   
            if(tempc == 'A')
            {
                st = {i,j};
            }
            else if(tempc == 'B')
            {
                ed = {i,j};
            }
            else if(tempc == 'X') 
            {
                temp[cnt++] = {i,j};
            }
        }
    }
    temp[0] = st;
    temp[cnt++] = ed;
    for(int i=0;i<cnt;i++)
    {
        for(int j=0;j<cnt;j++)
        {
            if(i == j) continue;
            int w = abs(temp[i].first - temp[j].first) + abs(temp[i].second-temp[j].second);

            if(w > k) continue;

            adj[i].push_back({j,w});
        }
    }

    priority_queue<pii> pq;
    fill(dist,dist+cnt,INT_MAX);
    dist[0] = 0;
    pq.push({0,0});

    while(not pq.empty())
    {
        int now = pq.top().second;
        pq.pop();

        if(visited[now]) continue;
        visited[now] = true;

        for(auto e:adj[now])
        {
            int next = e.first;
            int w = e.second;

            if(dist[now] + w < dist[next])
            {
                dist[next] = dist[now]+w;
                pq.push({-dist[next],next});
            }
        }
    }

    if(dist[cnt-1] == INT_MAX) printf("-1");
    else printf("%d",dist[cnt-1]); 

    return 0;
}