#include<stdio.h>
#include<math.h>
#define max(a,b) (a>b)?a:b
typedef struct pos
{
    int x,y;
}POS;

int n,m,b,k,q;
int a[1005][1005];
POS bomb[10005];

int main()
{
    scanf("%d%d%d%d%d",&n,&m,&b,&k,&q);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++) scanf("%d",&a[i][j]);
    }

    for(int i=0;i<b;i++) scanf("%d%d",&bomb[i].x, &bomb[i].y);

    int v,w;
    while(q--)
    {
        scanf("%d%d",&v,&w);

        int cnt = 0;
        for(int i=0;i<b;i++)
        {
            //printf("->%d\n", abs(bomb[i].x-v)+abs(bomb[i].y - w));
            if(abs(bomb[i].x-v)+abs(bomb[i].y - w) <= k) cnt++;
        }

        printf("%d\n",max(0,a[v][w]-cnt));
    }

    return 0;
}