#include <bits/stdc++.h>
using namespace std;

int n;
int arr[2505];

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int sn = 0, bn = 0, st, ed, tmp = 0;

    for (int i = 0; i < n; i++)
    {
        sn += arr[i];
        if (sn < arr[i])
        {
            sn = arr[i];
            tmp = i;
        }

        if (bn < sn)
        {
            bn = sn;
            ed = i;
            st = tmp;
        }
    }

    if (bn <= 0)
        printf("Empty sequence");

    else
    {
        for (int i = st; i <= ed; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n%d", bn);
    }
    return 0;
}