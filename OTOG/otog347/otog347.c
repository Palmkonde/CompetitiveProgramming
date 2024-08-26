#include<stdio.h>
#define ll long long

int n,m;
char cmd;
ll arr[30005];

int main()
{
    scanf("%d%d",&n,&m);

    while(m--)
    {
        scanf(" %c",&cmd);
        
        if(cmd == 'B')
        {
            int a;
            ll b;
            scanf("%d%lld",&a,&b);
            arr[a] = b;
        }

        if(cmd == 'C')
        {
            int a;
            ll mx = -(int)(1 << 31);
            scanf("%d",&a);

            for(int i=1;i<=a;i++) mx = (arr[i] > mx) ? arr[i]:mx;

            printf("%lld\n",mx);
        }
    }

    return 0;
}