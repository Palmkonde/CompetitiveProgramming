#include <stdio.h>
#include <stdlib.h>

int n;
int a[2005], b[2005];

void Msort(int l, int r, int *t)
{
    if (l >= r)
        return;

    int mid = l + (r - l) / 2;
    Msort(l, mid, t);
    Msort(mid + 1, r, t);

    int n1 = mid - l + 1;
    int n2 = r - mid;

    int t1[n1], t2[n2];

    for (int i = 0; i < n1; i++)
    {
        t1[i] = t[l + i];
    }

    for (int j = 0; j < n2; j++)
    {
        t2[j] = t[mid + 1 + j];
    }

    int i, j, k;
    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (t1[i] <= t2[j])
        {
            t[k] = t1[i];
            i++;
        }
        else
        {
            t[k] = t2[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        t[k] = t1[i];
        k++;
        i++;
    }

    while (j < n2)
    {
        t[k] = t2[j];
        k++;
        j++;
    }
}

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &b[i]);
    }

    Msort(0, n - 1, a);
    Msort(0, n - 1, b);

    long int ans = 0;

    for (int i = 0; i < n; i++)
    {
        ans += abs(a[i] - b[i]);
    }

    printf("%lld", ans);

    return 0;
}