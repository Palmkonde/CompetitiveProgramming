#include<bits/stdc++.h>
using namespace std;

const int N = 100005;

int n,q,tmp;
int qs[N];

int main()
{
    scanf("%d%d",&n,&q);

    for(int i=1;i<=n;i++) scanf("%d",&qs[i]);
    sort(qs+1,qs+n+1,greater<int>());
    for(int i=1;i<=n;i++) qs[i] += qs[i-1];
    
    while(q--)
    {
        scanf("%d",&tmp);

        int ans = lower_bound(qs,qs+1+n,tmp) - (qs);
        (ans < n) ? printf("%d",ans) : printf("NO");
        printf("\n");    
    }

    return 0;
}