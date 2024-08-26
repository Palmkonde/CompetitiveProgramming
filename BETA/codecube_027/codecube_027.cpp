#include<bits/stdc++.h>
using namespace std;
using tii = tuple<int,int>;
int n,t;
bool vis[(1 << 21) + 5];
queue<tii> q;
int main()
{
    scanf("%d",&n);
    int st = 0;
    for(int i=1;i<=n;i++)
    {   
        scanf("%d",&t);
        if(t) st |= (1 << i);
    }  
    for(int i=1;i<=n;i++){q.push({0,st});}
    while(not q.empty())
    {
        int cnt,tmp;
        tie(cnt,tmp) = q.front();
        q.pop();
        if(tmp == 0)
        {
            printf("%d",cnt);
            return 0;
        }
        if(vis[tmp]) continue;
        vis[tmp] = 1;
        for(int i=1;i<=n;i++)
        {
            int mask = tmp;
            mask ^= (1 << i);
            if(i-1 >= 1) mask ^= (1 << i - 1);
            if(i+1 <= n) mask ^= (1 << i + 1);     
            q.push({cnt+1,mask});
        }
        //cout << "\n";
    }
    printf("-1");
}