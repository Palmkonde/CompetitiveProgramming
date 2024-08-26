#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ll long long
#define N 200005
#define M 1000005

typedef struct tuple
{
    ll w, u, v;
} TUPLE;

TUPLE make_tuple(ll a, ll b, ll c)
{
    TUPLE tmp;
    tmp.w = a;
    tmp.u = b;
    tmp.v = c;
    return tmp;
}

int Tsize;
TUPLE Tree[M];

void push(TUPLE v)
{
    Tree[Tsize++] = v;

    // fixup
    int node = Tsize - 1;
    TUPLE tmp = v;

    while (node > 0)
    {
        int p = (node - 1) / 2;

        if (Tree[p].w >= tmp.w)
            break;

        Tree[node] = Tree[p];
        node = p;
    }
    Tree[node] = tmp;
}

void pop()
{
    Tree[0] = Tree[--Tsize];

    // fixdown
    int node = 0;
    TUPLE tmp = Tree[node];
    int c;

    while ((c = 2 * node + 1) < Tsize)
    {
        if (c + 1 < Tsize && Tree[c].w < Tree[c + 1].w)
            c++;

        if (Tree[c].w < tmp.w)
            break;

        Tree[node] = Tree[c];
        node = c;
    }
    Tree[node] = tmp;
}

ll n, m, w, u, v;
int p[N], h[N];

int root(int x)
{
    if (p[x] == -1)
    {
        return x;
    }
    return p[x] = root(p[x]);
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main()
{
    scanf("%lld %lld", &n, &m);

    for (int i = 0; i < m; i++)
    {
        scanf("%lld%lld%lld", &u, &v, &w);
        push(make_tuple(w - 1, u, v));
    }

    memset(p, -1, sizeof(p));
    for (int i = 1; i <= n; i++)
        h[i] = 1;

    ll ans = 0;
    while (Tsize)
    {
        TUPLE now = Tree[0];
        pop();

        int pa = root(now.u);
        int pb = root(now.v);

        if (pa != pb)
        {
            if (h[pa] < h[pb])
                swap(&pa, &pb);

            p[pb] = pa;
            h[pa] += h[pb];
            ans += now.w;
        }
    }

    printf("%lld", ans);

    return 0;
}