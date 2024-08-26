#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll n,s,c;

struct pqData
{
    ll sz ,amt;

    bool operator<(const pqData &other) const 
    {
        return this->sz > other.sz;
    }
};

priority_queue<pqData> pq;
stack<pqData> stk;

int main()
{
    scanf("%lld",&n);
    
    for(int i=0;i<n;i++)
    {
        scanf("%lld%lld",&s,&c);
        pq.push({s,c});
    }
    
    int cnt = 0;
    ll tmp = 0;

    while(not pq.empty())
    {
        pqData now = pq.top();
        pq.pop();
        
        // printf("%lld %lld\n",lastsz,now.sz);
        // printf("%lld %lld\n\n",lastamt,now.amt);

        if(!stk.empty())
        {
            pqData last = stk.top();
            if(now.sz != last.sz)
            {
                while(not stk.empty())
                {
                    tmp += stk.top().amt;
                    stk.pop(); 
                }

                if(tmp == 1) cnt++;
                else
                {
                    pq.push({last.sz*2, (tmp)/2});
                    cnt+=(tmp%2==1);   
                }
                tmp=0;
            }
        }

        stk.push(now);

        if(pq.empty())
        {
            while(not stk.empty())
            {
               tmp += stk.top().amt;
               stk.pop(); 
            }
            if(tmp == 1) cnt++;
            else
            {
                pq.push({now.sz*2, (tmp)/2});
                cnt+=(tmp%2==1);   
            }
            tmp=0;
        }

    }
    
    //cnt += (lastamt==1);
    printf("%d",cnt);

    return 0;
}