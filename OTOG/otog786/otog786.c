#include <stdio.h>
#include <stdlib.h>
#define MAX(x, y) (x > y) ? x : y

int n, m;
int num[1000005];

void mSort(int l, int r)
{
    if (l >= r)
        return;

    int mid = l + (r - l) / 2;
    mSort(l, mid);
    mSort(mid + 1, r);

    int n1 = mid - l + 1;
    int n2 = r - mid;

    int t1[n1], t2[n2];

    for (int i = 0; i < n1; i++)
    {
        t1[i] = num[l + i];
    }

    for (int i = 0; i < n2; i++)
    {
        t2[i] = num[mid + 1 + i];
    }

    int i, j, k;
    i = j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (t1[i] >= t2[j])
        {
            num[k++] = t1[i++];
        }
        else if (t1[i <= t2[j]])
        {
            num[k++] = t2[j++];
        }
    }

    while (i < n1)
    {
        num[k++] = t1[i++];
    }

    while (j < n2)
    {
        num[k++] = t2[j++];
    }
}

int main()
{
    scanf("%d%d", &n, &m);

    int mx = -1;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
        mx = MAX(mx, num[i]);
    }

    int a;
    while (m--)
    {
        scanf("%d", &a);
        int cnt = a / mx;
        int rem = a % mx;

        cnt += !(rem == 0);

        printf("%d\n", cnt);
    }

    return 0;
}