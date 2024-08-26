#include <bits/stdc++.h>
using namespace std;

int a, b;

int main()
{
    scanf("%d%d", &a, &b);

    int n = __gcd(a, b);

    for (int i = 1; i <= n; i++)
    {
        if (!(n % i))
        {
            printf("%d %d %d\n", i, a / i, b / i);
        }
    }

    return 0;
}