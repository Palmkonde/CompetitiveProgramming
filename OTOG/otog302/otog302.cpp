#include<bits/stdc++.h>
using namespace std;

const int N = 55;

int n,m;
int color[N];
vector<int> adj[N];

bool is_safe(int u,int c)
{
    for(auto e:adj[u])
    {
        if(color[e] == c) return false;
    }
    return true;
}

bool coloring(int u,int mid)
{
    if(u == n) return true;

    for(int i=1;i<=mid;i++)
    {
        if(is_safe(u,i))
        {
            color[u] = i;
            if(coloring(u+1,mid)) return true;
        }
        color[u] = 0;
    }
    return false;
}

int main()
{
    scanf("%d%d",&n,&m);

    int u,v;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int l = 0,r = 50;
    
    while(l < r)
    {
        int mid = l + (r-l)/2;
        if(coloring(0,mid))
        {
            r = mid;
        }else l = mid+1;
    }

    printf("%d",r);

    return 0;
}