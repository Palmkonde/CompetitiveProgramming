#include <bits/stdc++.h>
using namespace std;

bool a[200];
int n;

int main()
{
    scanf("%d", &n);

    a[6] = a[9] = a[20] = 1;
    for (int i = 6; i <= n; i++)
    {
        if (a[i])
            a[i + 6] = a[i + 9] = a[i + 20] = 1;
    }

    if (n < 6)
    {
        printf("no");
        return 0;
    }

    for (int i = 6; i <= n; i++)
    {
        if (a[i])
            printf("%d\n", i);
    }

    return 0;
}