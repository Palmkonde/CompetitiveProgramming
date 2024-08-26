#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> adj[100005];
int indge[100005];

int main()
{
    scanf("%d %d", &n, &m);

    while(m--)
    {
        int u,v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);    
        indge[v]++;
    }

    queue<int> q;
    for(int i=1;i<=n;i++)
    {
        if(indge[i] == 0)
        {
            q.push(i);
        }
    }

    if(q.size() == 0)
    {
        printf("no"); 
        return 0;
    }

    vector<int> ans;

    while(not q.empty())
    {
        int now = q.front();
        q.pop();

        ans.push_back(now);

        for(auto e : adj[now])
        {
            indge[e]--;
            if(indge[e] == 0)
            {
                q.push(e);
            }
        }
    }

    if(n != ans.size())
    {
        printf("no");
        return 0;
    }

    for(auto e:ans)
    {
        printf("%d\n",e);
    }
    return 0;
}