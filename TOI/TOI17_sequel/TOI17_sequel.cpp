#include<bits/stdc++.h>
using namespace std;

const int N = 100002;

int n,q;
int num[N];

int main()
{
    scanf("%d %d", &n, &q);
    for(int i=1;i<=n;i++)
    {
        scanf("%d", &num[i]);
        num[i] = num[i]+num[i-1];
    }

    while(q--)
    {
        int l,m,r;
        int64_t ans = 0;
        scanf("%d %d %d",&l, &m, &r);
        
        if(m==1)
        {
            ans += num[r]-num[l-1];
        }

        else
        {
            for(int i=l;i<=r;i+=m)
            {
                ans += num[i]-num[i-1];
            }
        }
        printf("%lld ", ans);

    }

    return 0;
}