#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODE
{
    int w;
    int u;
    int v;
} NODE;

NODE Tree[500005];
int Tsize;

void push(int cost, int x, int y)
{
    Tree[Tsize].w = cost;
    Tree[Tsize].u = x;
    Tree[Tsize].v = y;

    Tsize++;

    // fixup
    int node = Tsize - 1;
    NODE tmp = Tree[node];
    while (node > 0)
    {
        int p = (node - 1) / 2;

        if (tmp.w >= Tree[p].w)
            break;

        Tree[node] = Tree[p];
        node = p;
    }
    Tree[node] = tmp;
}

void pop()
{
    Tree[0] = Tree[Tsize - 1];
    Tsize--;

    // fixdown;
    int node = 0;
    NODE tmp = Tree[node];
    int c;
    while ((c = 2 * node + 1) < Tsize)
    {
        if (c + 1 < Tsize && (Tree[c].w > Tree[c + 1].w))
            c++;

        if (Tree[c].w >= tmp.w)
            break;

        Tree[node] = Tree[c];
        node = c;
    }
    Tree[node] = tmp;
}

void swap(int i, int j)
{
    i = i ^ j;
    j = i ^ j;
    i = j ^ i;
}

int n,
    m;
int u, v, w, cost;
int parent[500005], h[500005] = {[0 ... 500004] = 1};

int root(int x)
{
    if (parent[x] == -1)
    {
        return x;
    }

    return parent[x] = root(parent[x]);
}

int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        push(w, u, v);
    }

    memset(parent, -1, sizeof(parent));

    while (Tsize)
    {
        NODE now = Tree[0];
        pop();

        int pa, pb, c;
        c = now.w;
        pa = root(now.u);
        pb = root(now.v);

        if (pa != pb)
        {
            if (h[pa] < h[pb])
                swap(pa, pb);

            h[pa] += h[pb];

            parent[pb] = pa;
            cost += c;
        }
    }

    printf("%d", cost);

    return 0;
}