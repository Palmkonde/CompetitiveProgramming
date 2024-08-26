#include <stdio.h>
#include <stdlib.h>
#define N 1000005

typedef struct vector
{
    int Msize;
    int Mcap;
    int *e;
} vector;

vector *newVec()
{
    vector *new = malloc(sizeof(vector));
    new->Msize = 0;
    new->Mcap = 1;
    new->e = malloc(sizeof(int) * new->Mcap);
    return new;
}

void push_back(vector *vec, int val)
{
    if (vec->Mcap == vec->Msize)
    {
        vec->Mcap *= 2;
        vec->e = realloc(vec->e, vec->Mcap * sizeof(int));
    }
    vec->e[vec->Msize++] = val;
}

vector *adj[N];
int m;

void dfs(int u, int p)
{
    printf("%d ", u);
    for (int i = 0; i < adj[u]->Msize; i++)
    {
        if (adj[u]->e[i] == p)
            continue;

        // printf("->%d\n", adj[u]->e[i]);

        dfs(adj[u]->e[i], u);
    }
}

int main()
{

    for (int i = 1; i <= N; i++)
    {
        adj[i] = newVec();
    }

    scanf("%d", &m);

    int u, v;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);
        push_back(adj[u], v);
        push_back(adj[v], u);
    }

    dfs(1, -1);

    return 0;
}