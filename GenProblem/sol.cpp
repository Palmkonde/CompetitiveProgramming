#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5+5;

ll n,q,k; // ขนาด array, จำนวนคำถาม, ขนาด subarray
ll arr[N];

bool check(ll &mid) //O(N)
{
    ll cnt = 0;
    ll sum = 0;

    for(int i=0;i<n;i++)
    {
        sum += arr[i];
        if(sum >= mid)
        {
            cnt++;
            sum=0;
        }
    }

    cnt += (sum != 0);

    if(cnt > k) return true;  // ต้องเพิ่มค่า mid 
    else return false; //ต้องลดค่า mid  
}

int main()
{
   

        scanf("%lld%lld",&n,&q);

        for(int i=0;i<n;i++) scanf("%lld",&arr[i]);

        while(q--) 
        {
            scanf("%lld",&k);
            
            ll l=0,r=LLONG_MAX; 
            while(l<r)
            {
                ll mid = l+(r-l)/2;
                if(check(mid)) l=mid+1;
                else r=mid;

            }
            printf("%lld\n",l);
        }
    return 0;
}
