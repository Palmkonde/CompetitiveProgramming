#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pair
{
    int w;
    int node;
} Pair;

Pair Tree[200005];
int Tsize;

void push(int val, int pos)
{
    Tree[Tsize].w = val;
    Tree[Tsize].node = pos;
    Tsize++;

    // fixup
    int node = Tsize - 1;
    Pair tmp = Tree[node];
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

    // fixdown
    int node = 0;
    Pair tmp = Tree[node];
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

typedef struct node
{
    int vertex;
    struct node *next;
    int w;
} node;

typedef struct Graph
{
    int numberV;
    node **adjlist;
} Graph;

node *createNode(int v, int w)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->vertex = v;
    newNode->w = w;

    return newNode;
}

Graph *createGraph(int number)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));

    graph->numberV = number;
    graph->adjlist = malloc(number * sizeof(node *));

    for (int i = 0; i < number; i++)
    {
        graph->adjlist[i] = NULL;
    }

    return graph;
}

// undirected
void addEdge(Graph *graph, int u, int v, int w)
{
    node *newNode = createNode(v, w);
    newNode->next = graph->adjlist[u];
    graph->adjlist[u] = newNode;

    newNode = createNode(u, w);
    newNode->next = graph->adjlist[v];
    graph->adjlist[v] = newNode;
}

int n, m, s, t, u, v, w;
int dist[10005];

int main()
{
    scanf("%d%d%d%d", &n, &m, &s, &t);

    Graph *graph = createGraph(n);

    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        addEdge(graph, u, v, w);
    }

    for (int i = 0; i < n; i++)
    {
        dist[i] = 1e9;
    }

    dist[s] = 0;
    push(dist[s], s);

    while (Tsize)
    {
        Pair now = Tree[0];
        pop();

        if (dist[now.node] > now.w)
            continue;

        node *tmp = graph->adjlist[now.node];
        while (tmp)
        {
            int nx = tmp->vertex;
            w = tmp->w;

            if (dist[nx] > dist[now.node] + w)
            {
                dist[nx] = dist[now.node] + w;
                push(dist[nx], nx);
            }

            tmp = tmp->next;
        }
    }

    printf("%d", dist[t]);

    return 0;
}