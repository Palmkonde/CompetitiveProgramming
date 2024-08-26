#include <stdio.h>
#include <stdlib.h>
#define M 200005

int n, m, a, b, temp = 0;

struct Pair
{
    int pos;
    int st;
} typedef Pair;

Pair arr[M];

int cmpfunc(const void *a, const void *b)
{
    Pair *pa = (Pair *)a;
    Pair *pb = (Pair *)b;

    if ((pa->pos - pb->pos) == 0)
    {
        return (pa->st - pb->st);
    }
    else
        return (pa->pos - pb->pos);
}

int main()
{
    scanf("%d %d", &n, &m);

    for (int i = 0; i < 2 * n; i += 2)
    {
        scanf("%d %d", &a, &b);
        arr[i].pos = a + 1;
        arr[i + 1].pos = b;
        arr[i].st = 1;
        arr[i + 1].st = -1;
    }

    for (int i = 2 * n; i < 2 * n + m; i++)
    {
        scanf("%d", &a);
        arr[i].pos = a;
        arr[i].st = 99;
    }

    qsort(arr, 2 * n + m, sizeof(Pair), cmpfunc);

    int ans = 0;
    for (int i = 0; i < 2 * n + m; i++)
    {
        if (arr[i].st == 99)
        {
            ans += temp;
            continue;
        }

        temp += arr[i].st;
    }

    printf("%d", (ans % 2007));

    return 0;
}