#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct vector 
{
    int *v;
    int mSize;
    int mCap;
}VECTOR;

int n,m;
int parent[100005];
VECTOR *adj[100005];
VECTOR *ans;
char vis[100005];

VECTOR *createVector(int size)
{
    VECTOR *new = malloc(sizeof(VECTOR));
    new->v = malloc(sizeof(int)*size);
    new->mCap = size;
    new->mSize = 0;

    return new;
}

void push(VECTOR *k, int e)
{
    k->v[k->mSize++] = e;
    if(k->mSize == k->mCap)
    {
        k->mCap *= 2;
        k->v = realloc(k->v,sizeof(int) * k->mCap);
    }
}

void pop(VECTOR *vec)
{
    vec->v[--vec->mSize] = 0;
}

void mSort(int l,int r)
{
    if(l >= r) return;

    int mid = l + (r-l)/2;
    mSort(l,mid);
    mSort(mid+1,r);

    int n1 = mid-l+1;
    int n2 = r-mid;

    int tmp1[n1],tmp2[n2];

    for(int i=0;i<n1;i++)
    {
        tmp1[i] = ans->v[l+i];
    }

    for(int i=0;i<n2;i++)
    {
        tmp2[i] = ans->v[mid+i+1];
    }

    int i=0,j=0,k=l;

    while(i < n1 && j < n2)
    {
        if(tmp1[i] < tmp2[j])
        {
            ans->v[k] = tmp1[i++];
        }else ans->v[k] = tmp2[j++];

        k++;
    }

    while(i < n1) ans->v[k++] = tmp1[i++];
    while(j < n2) ans->v[k++] = tmp2[j++];
}

int fg = 0,start=-1,end;
void dfs(int u,int p)
{
    vis[u] = 1;
    for(int i=0;i<adj[u]->mSize;i++)
    {
        int nx = adj[u]->v[i];

        if(nx == p) continue;
        if(vis[nx])
        {
            end = nx;
            start = u;
            return;
        } 

        parent[nx] = u;
        dfs(nx,parent[nx]);
    }
}

int main()
{
    scanf("%d%d",&n,&m);

    for(int i=0;i<=n;i++) adj[i] = createVector(1);
    
    ans = createVector(1);

    int u,v;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&u,&v);
        push(adj[u],v);
        push(adj[v],u);
    }

   
    int rt = -1;
    for(int i=0;i<=n;i++)
    {
        if(adj[i]->mSize == 1){rt = i;break;}
    }    
    dfs(rt,-1);
    if(start == -1) {printf("NO");return 0;}

    printf("YES\n");
    push(ans,start);
    for(int v = end; v != start ; v = parent[v]) push(ans,v);
    
    mSort(0,ans->mSize-1);
    for(int i=0;i<ans->mSize;i++)
    {
        printf("%d ",ans->v[i]);
    }

    return 0;
}