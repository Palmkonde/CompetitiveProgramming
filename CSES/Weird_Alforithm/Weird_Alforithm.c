#include <stdio.h>
#define ll long long
void r(ll n)
{
    printf("%lld ", n);

    if (n == 1)
        return;
    else
        (n & 1) ? r(3 * n + 1) : r(n / 2);
}

int main()
{
    ll n;
    scanf("%lld", &n);

    r(n);

    return 0;
}