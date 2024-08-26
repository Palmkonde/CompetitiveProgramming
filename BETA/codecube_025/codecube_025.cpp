#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 605;

ll a[N],qs[N];
ll dp[N][N];
ll n;

ll mcm(int l,int r)
{
    if(l == r) return 0;
    if(dp[l][r]) return dp[l][r];

    ll res = INT_MIN;
    for(int k=l;k<r;k++)
    {
        int mn = min(qs[k] - qs[l-1], qs[r] - qs[k]);
        int mx = max(qs[k] - qs[l-1], qs[r] - qs[k]);
        res = max(res,mcm(l,k) + mcm(k+1,r) + (2*mn) + mx);
    }
    return dp[l][r] = res;
}

int main()
{
    scanf("%lld",&n);

    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);

    for(int i=1;i<=n;i++) qs[i] = qs[i-1] + a[i];

    printf("%lld", mcm(1,n));

    return 0;
}
