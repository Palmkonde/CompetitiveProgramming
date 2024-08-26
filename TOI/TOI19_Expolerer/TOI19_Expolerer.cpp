#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9+7;
const int N = 500005;

int n,a,b;
ll fac[N];
bool vis[N];
vector<int> adj[N];
stack<int> st;

/*
ข้อนี้ พอดูดีๆ ก็แค่เรียงสับเปลี่ยนตัว child node ของทุกตัว
*/

int main()
{
    scanf("%d",&n);

    // permutation ใช้ factorial จะได้เร็วๆเลย เราก็คำนวนไว้ก่อน
    fac[0] = 1;
    fac[1] = 1;
    for(int i=2;i<=500000;i++)
    {
        fac[i] = i*fac[i-1];
        fac[i] %= MOD;
    }

    
    //  **น่าจะมีวิธีอื่นดีกว่า**
    for(int i=0;i<2*n-1;i++)
    {
        scanf("%d",&a);
        if(!i)
        {
            b = a;
            vis[b] = true;
            st.push(a);
            continue;
        }
        if(vis[a])
        {
            st.pop();
    
            if(st.empty()) continue;
            
            b = st.top();
            continue;
        }

        //printf("%d %d %d\n",i,b,a);
        adj[b].push_back(a);
        st.push(a);
        b = a;
        vis[b] = true;
    }

    /*
        ลองปริ้นๆดู
        for(int i=1;i<=n;i++)
        {
            printf("%d: ",i);
            for(auto e:adj[i]) printf("%d ",e);
            printf("\n");
        }
    */

    ll res = 1;
    for(int i=1;i<=n;i++)
    {
        res *= fac[adj[i].size()];
        res %= MOD;
    }

    printf("%lld",res);

    return 0;
}