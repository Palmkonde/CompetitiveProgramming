#include <stdio.h>
#include <stdlib.h>
#define N 100006
#define MAX(a, b) (a > b) ? a : b

typedef struct PAIR
{
    int first;
    int second;
} PAIR;

typedef struct VECTER
{
    PAIR *arr;
    int mSize;
    int mCap;
} VECTER;

VECTER *createVECTER(int size)
{
    VECTER *newVECTER = (VECTER *)malloc(sizeof(VECTER));
    newVECTER->arr = (PAIR *)malloc(sizeof(PAIR) * size);
    newVECTER->mSize = 0;
    newVECTER->mCap = size;

    return newVECTER;
}

void pushBack(VECTER *v, PAIR element)
{
    v->arr[v->mSize++] = element;
    if (v->mSize == v->mCap)
    {
        v->mCap *= 2;
        v->arr = realloc(v->arr, sizeof(PAIR) * v->mCap);
    }
}

PAIR makePair(int f, int s)
{
    PAIR newPAIR;
    newPAIR.first = f;
    newPAIR.second = s;

    return newPAIR;
}

int n, u, v, w;
VECTER *adj[N];

int dfs(int x, int p)
{
    int sum = 0;
    for (int i = 0; i < adj[x]->mSize; i++)
    {
        int nx = adj[x]->arr[i].first;
        int nw = adj[x]->arr[i].second;

        if (nx == p)
            continue;

        sum = MAX(sum, dfs(nx, x) + nw);
    }

    return sum;
}

int main()
{
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        adj[i] = createVECTER(1);
    }

    for (int i = 0; i < n - 1; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        pushBack(adj[u], makePair(v, w));
        pushBack(adj[v], makePair(u, w));
    }

    printf("%d", dfs(1, 0));

    return 0;
}