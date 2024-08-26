#include <bits/stdc++.h>
using namespace std;

int n;
int ans[15];

int main()
{
    scanf("%d", &n);

    int a, b, m, c;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d/%d/%d", &a, &b, &m, &c);

        ans[m]++;
    }

    for (int i = 1; i <= 12; i++)
    {
        printf("%d %d\n", i, ans[i]);
    }

    return 0;
}