#include <stdio.h>
#include <stdlib.h>
#define INF 1e9

typedef struct Pair
{
    int first;
    int seconde;
} Pair;

Pair Tree[4 * 9005];
int Tsize;

void fixup(int node)
{
    Pair tmp = Tree[node];

    while (node > 0)
    {
        int p = (node - 1) / 2;

        if (Tree[p].first <= tmp.first)
            break;

        Tree[node] = Tree[p];
        node = p;
    }
    Tree[node] = tmp;
}

void fixdown(int node)
{
    Pair tmp = Tree[node];

    int c;
    while ((c = 2 * node + 1) < Tsize)
    {
        if (c + 1 < Tsize && (Tree[c].first > Tree[c + 1].first))
            c++;

        if (Tree[c].first >= tmp.first)
            break;

        Tree[node] = Tree[c];
        node = c;
    }
    Tree[node] = tmp;
}

void push(int val, int pos)
{
    Tree[Tsize].first = val;
    Tree[Tsize].seconde = pos;

    Tsize++;
    fixup(Tsize - 1);
}

void pop()
{
    Tree[0] = Tree[Tsize - 1];
    Tsize--;
    fixdown(0);
}

int n, m, u, v, w;
int inMst[105];
int dist[105];
int adj[105][9005];

int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        adj[u][v] = w;
        adj[v][u] = w;
    }

    for (int i = 0; i < n; i++)
    {
        dist[i] = INF;
        for (int j = 0; j < n; j++)
        {
            if (!adj[i][j])
                adj[i][j] = INF;

            if (i == j)
                adj[i][j] = 0;
        }
    }

    dist[0] = 0;
    push(dist[0], 0);

    while (Tsize)
    {
        Pair now = Tree[0];
        pop();

        if (inMst[now.seconde])
            continue;

        inMst[now.seconde] = 1;

        for (int i = 0; i < n; i++)
        {
            if ((adj[now.seconde][i] == INF || now.seconde == i))
                continue;

            int nx = i;
            w = adj[now.seconde][nx];

            if (dist[nx] > w && !inMst[nx])
            {
                dist[nx] = w;
                push(dist[nx], nx);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        // printf("%d ", dist[i]);
        if (dist[i] != INF)
            ans += dist[i];
    }

    printf("%d", ans);

    return 0;
}