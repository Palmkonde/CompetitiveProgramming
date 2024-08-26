#include<bits/stdc++.h>
using namespace std;

const int N = 500005;

int n,m,st,ed;
int parent[N],cnt[N];
bool vis[N];
vector<int> adj[N],ans;

void iscycle(int u,int p)
{
    vis[u] = true;

    for(auto e:adj[u])
    {   
        if(e == p) continue;
        if(vis[e])
        {
            ed = u;
            st = e;
            return;
        }     

        parent[e] = u;
        iscycle(e, parent[e]);    
    }
}

void dfs(int u,int p)
{
    vis[u] = 1;

    for(auto e:adj[u])
    {
        if(e == p) continue;
        if(vis[e]) continue;

        dfs(e,u);
        cnt[u] += cnt[e] + 1;
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    
    int u,v;
    int l = -1;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);

        if(adj[u].size() == 1) l = u;
    }    

    iscycle(l,-1);
    fill_n(vis,N,0);
    
    ans.push_back(ed);
    vis[ed] = 1;
    for(int v = st; v != ed; v = parent[v])
    {
        vis[v] = 1;
        ans.push_back(v);
    }

    if(!vis[m])
    {
        fill_n(vis,N,0);
        dfs(m,-1);
        goto skip;
    }
    
    for(auto e:ans) dfs(e,-1);
    
skip:
    cnt[m] = 0;
    int idx = -1,mx = -1;
    for(int i=1;i<=n;i++)
    {
        if(i == m) continue;
        if(cnt[i] > mx) mx = cnt[i],idx=i;
    }
    printf("%d\n%d",idx,mx);
    
    return 0;
}

/*
12 7
1 2
1 6
1 7
1 12
6 8
6 9
2 3
2 10
10 11
3 4
4 5
5 12
*/