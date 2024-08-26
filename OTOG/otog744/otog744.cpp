#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e6+5;

ll a,s;
ll arr[N],qs[N];

int main()
{
    scanf("%lld %lld",&a,&s);

    for(int i=1;i<=a;i++)
    {
        ll tmp;
        scanf("%lld",&tmp);
        qs[i] = qs[i-1] + tmp;
    }

    int l=1,r=1;
    int ans = N+1;
    while(l <= a and r <= a)
    {
        if(qs[r] - qs[l-1] >= s) ans = min(ans,r-l+1),l++;
        else r++;
    }

    printf("%d",ans);

    return 0;
}