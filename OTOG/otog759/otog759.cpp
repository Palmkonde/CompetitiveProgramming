#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll,int>;

const int N = 5*1e4+5;

int n,m,k,tmp,u,v;
int c[N];
ll ans;
bool first = true;
bool vis[N];
vector<int> adj[N],st;
priority_queue<pii, vector<pii>, greater<pii>> pq;

int main()
{

    scanf("%d%d%d",&n,&m,&k);

    for(int i=0;i<k;i++)
    {
        scanf("%d",&tmp);
        st.push_back(tmp);
    }
    for(int i=0;i<n;i++) scanf("%d",&c[i]);
    for(auto &e:st) pq.push({c[e],e}),vis[e] = true;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int av = n;
    while(not pq.empty())
    {
        int now = pq.top().second;
        ll w = pq.top().first;
        pq.pop();
        ans += w;   

        for(auto nx:adj[now])
        {
            if(vis[nx]) continue;
            pq.push({c[nx]+w,nx});
            vis[nx] = true;
        }
    }

    printf("%lld",ans);

    return 0;
}