#include<stdio.h>
#include<stdlib.h>
#define ll long long
#define max(a,b) (a>b) ? a:b

int t;
long long qs[100005];

int main()
{
    scanf("%d",&t);

    int n,q;
    while(t--)
    {
        scanf("%d%d",&n,&q);
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&qs[i]);
            if(i) qs[i] += qs[i-1];
        }

        int l,r;
        while(q--)
        {
            scanf("%d%d",&l,&r);
            printf("%lld\n",qs[r]-qs[l-1]);
        }

    }

    return 0;
}