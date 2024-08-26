#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;

const int N = 100005;
const int M = 300005;

struct Edge
{
    int u,v,w;
    Edge(int a,int b,int c) 
    {
        u=a,v=b,w=c;
    }

    bool operator<(const Edge &other) const
    {
        return this->w < other.w;
    }
};

ll n,m,cost, mn, ans1, ans2;
int u,v,w;
vector<pii> adj[N];
vector<Edge> edge;
int parent[N], h[N];

int root(int x)
{
    if(parent[x] == -1)
    {
        return x;
    }
    return parent[x] = root(parent[x]);
}

ll dfs(int node,int pnode)
{   
    ll sum = 0;
    ll otherSum;
    ll edgeSum=0;

    for(auto e: adj[node])
    {
        int nx = e.first;
        if(nx == pnode) continue;

        sum = dfs(nx,node);
        otherSum = cost - sum - e.second;

        if(abs(sum - otherSum) < mn)
        {
            mn = abs(sum - otherSum);
            ans1 = sum;
            ans2 = otherSum;
        }
        
        edgeSum += sum + e.second;
    }
    return edgeSum;
}

int main()
{
    scanf("%lld %lld",&n,&m);

    fill_n(&(parent[0]),N,-1);
    fill_n(&(h[0]),N,1);

    for(int i=0;i<m;i++)
    {
        scanf("%d %d %d",&u,&v,&w);
        edge.push_back({u,v,w});
    }

    sort(edge.begin(),edge.end());

    for(auto e: edge)
    {
        int pa = root(e.u);
        int pb = root(e.v);

        if(pa != pb)
        {
            if(h[pa] < h[pb]) swap(pa,pb);
            
            h[pa] += h[pb];
            parent[pb] = pa;

            cost += e.w;
            adj[e.u].push_back({e.v,e.w});
            adj[e.v].push_back({e.u,e.w});
        }
    }

    printf("%lld\n",cost);
    
    mn = cost;
    dfs(0,-1);
    //printf("%lld\n",dfs(0,-1));
    printf("%lld %lld",min(ans1,ans2),max(ans1,ans2));

    return 0;
}