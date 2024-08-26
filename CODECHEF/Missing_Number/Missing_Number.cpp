#include <bits/stdc++.h>
using namespace std;

const int N = 2 * 1e5 + 5;

bool vis[N];

int n;
int main()
{
    scanf("%d", &n);

    int missing = 0, a;
    for (int i = 1; i <= n - 1; i++)
    {
        scanf("%d", &a);
        vis[a] = true;
    }

    for (int i = 1; i <= n; i++)
    {
        if (not vis[i])
        {
            missing = i;
        }
    }

    printf("%d", missing);

    return 0;
}