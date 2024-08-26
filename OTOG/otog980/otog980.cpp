#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll,ll>;

struct myHash
{
    size_t operator()(const ll v) const
    {
        size_t h;
        h ^= v + 0x9e3779b9 + (h << 6) + (h >> 2);
        
        return h;
    }
};

priority_queue<pii,vector<pii>, greater<pii>> pq;
int q;

int main() 
{
    scanf("%d",&q);
    
    while(q--)
    {
        ll k,ans;
        unordered_map<ll,int,myHash> mp;

        scanf("%lld",&k);
        
        pq.push({0,k});

        while(not pq.empty())
        {
            pii now = pq.top();
            pq.pop();
            
            if(mp[now.second]) continue;
            mp[now.second] = 1;

            // printf("->%lld %lld\n",now.first, now.second);
            if(now.second == 1)
            {
                ans = now.first;
                break;
            }

            if(!mp[now.second-1])
            {
                pq.push({now.first+1,now.second-1});
            }
            if(!mp[now.second+2])
            {
                pq.push({now.first+1,now.second+2});
            }

            if(now.second%3 == 0 and !mp[now.second/3] )
            {
                pq.push({now.first+3,now.second/3});
            }
        }
        while(not pq.empty()) pq.pop();

        printf("%lld\n",ans);
    }
    return 0;
}