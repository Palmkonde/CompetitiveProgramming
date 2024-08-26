#include<stdio.h>
#define max(a,b) (a>b) ? a:b

int n,m,k;
int qs[1005][1005];

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++) scanf("%d",&qs[i][j]);
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            qs[i][j] += qs[i-1][j] + qs[i][j-1] - qs[i-1][j-1];
        }
    }

    int mx = 0,tmp;
    for(int i=k;i<=n;i++)
    {
        for(int j=k;j<=m;j++)
        {
            tmp = qs[i][j] - qs[i-k][j] - qs[i][j-k] + qs[i-k][j-k];
            mx = max(mx,tmp);
        }
    }

    printf("%d",mx);

    return 0;
}