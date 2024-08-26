#include <stdio.h>
#include <stdlib.h>

int n, d, l, r;

long long recur(int n)
{
    int ll = (n * l) / d;
    int rr = (n * r) / d;

    int res = 0;

    if (ll < d)
        res++;

    else
        res += recur(ll);

    if (rr < d)
        res++;

    else
        res += recur(rr);

    return res;
}
int main()
{
    scanf("%d%d%d", &n, &l, &r);
    d = l + r;

    printf("%lld", recur(n));
    return 0;
}