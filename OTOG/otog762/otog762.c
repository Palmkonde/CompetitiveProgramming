#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct VECTER
{
    int *arr;
    int mSize;
    int mCap;
} VECTER;

VECTER *createVECTER(int size)
{
    VECTER *newVECTER = (VECTER *)malloc(sizeof(VECTER));
    newVECTER->arr = (int *)malloc(size * sizeof(int));
    newVECTER->mSize = 0;
    newVECTER->mCap = size;

    return newVECTER;
}

void pushBack(VECTER *v, int element)
{
    v->arr[v->mSize++] = element;
    if (v->mSize == v->mCap)
    {
        v->mCap *= 2;
        v->arr = (int *)realloc(v->arr, sizeof(int) * v->mCap);
    }
}

char color[100005]; // 1 red, 0 blue;

int t, a, b, n, m;

int main()
{
    scanf("%d", &t);

    while (t--)
    {
        scanf("%d%d", &n, &m);

        memset(color, -1, sizeof(color));

        VECTER *adj[100005];
        int queue[100005];

        for (int i = 0; i < n; i++)
        {
            adj[i] = createVECTER(1);
        }

        for (int i = 0; i < m; i++)
        {
            scanf("%d%d", &a, &b);
            pushBack(adj[a], b);
            pushBack(adj[b], a);
        }

        int front = 0, rear = 0;
        int fg = 0;

        queue[rear++] = 0;
        for (int i = 0; i < n; i++)
        {
            queue[rear++] = i;
            if (color[i] == -1)
                color[i] = 1;

            while (front != rear)
            {
                int now = queue[front++];

                for (int i = 0; i < adj[now]->mSize; i++)
                {
                    int nx = adj[now]->arr[i];

                    if (color[nx] != -1)
                    {
                        if (color[nx] == color[now])
                            fg = 1;

                        continue;
                    }

                    color[nx] = !color[now];
                    queue[rear++] = nx;
                }
            }

            if (front == rear)
                front = rear = 0;
        }

        (fg) ? printf("Gay found!\n") : printf("Gay not found!\n");
    }

    return 0;
}