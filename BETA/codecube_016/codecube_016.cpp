#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using ll = long long;
using namespace std;

ll n;
vector<ll> a;

int main()
{
    scanf("%lld",&n);

    ll t;
    for(int i=0;i<2*n;i++) scanf("%lld",&t), a.push_back(t);

    sort(all(a));

    ll ans = 0;
    for(int i=0,j=2*n-1;i<n;i++,j--)
    {
        //printf("%d %d\n",a[i],a[j]);
        ans += a[i] * a[j];
    }
    

    printf("%lld",ans);
    return 0;
}