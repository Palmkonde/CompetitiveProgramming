#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define max(a,b) (a > b) ? a:b

typedef struct POINT 
{
    int x;
    int y;
}point;

typedef struct n
{
    int w;
    int node;
}nn;

int n,Tsize;
int dist[13005];
char inMst[13005];
nn Tree[130005];
point pos[13005];

void push(int dist,int node)
{
    Tree[Tsize].w = dist;
    Tree[Tsize++].node = node;

    nn tmp = Tree[Tsize-1];
    int now = Tsize-1;
    int p;
    
    while (now > 0)
    {
        p = (now-1)/2;
        
        if(Tree[p].w > tmp.w) break;

        Tree[now] = Tree[p];
        now = p;
    }
    Tree[now] = tmp;
}

void pop()
{
    Tree[0] = Tree[--Tsize];

    nn tmp = Tree[0];
    int node = 0;
    int c;

    while((c=2*node+1) < Tsize)
    {
        if(c+1 < Tsize && Tree[c+1].w > Tree[c].w) c++;
        
        if(tmp.w > Tree[c].w) break;
        
        Tree[node] = Tree[c];
        node = c;
    }    
    Tree[node] = tmp;
}

int main()
{
    scanf("%d",&n);

    int a,b;
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&a,&b);
        pos[i].x = a;
        pos[i].y = b;
    }
    
    for(int i=0;i<n;i++) dist[i] = -1;
    
    dist[0] = 0;
    push(dist[0],0);

    while(Tsize)
    {
        nn now = Tree[0];
        pop();

        if(inMst[now.node]) continue;
        inMst[now.node] = 1;

        for(int i=0;i<n;i++)
        {
            if(i == now.node) continue;

            int w = max(abs(pos[now.node].x - pos[i].x), abs(pos[now.node].y - pos[i].y));


            if((dist[i] < w) && !inMst[i])
            {
                dist[i] = w;
                push(dist[i],i);
            }
        }
    }

    int ans = 0;
    for(int i=0;i<n;i++) ans += dist[i];

    printf("%d",ans);

    return 0;
}