#include <bits/stdc++.h>
using namespace std;

int n, k;
set<int> s;

int main()
{
    scanf("%d%d", &n, &k);

    int a;
    while (n--)
    {
        scanf("%d", &a);
        s.insert(a % k);
    }

    printf("%d\n", s.size());
    for (auto e : s)
    {
        printf("%d\n", e);
    }

    return 0;
}