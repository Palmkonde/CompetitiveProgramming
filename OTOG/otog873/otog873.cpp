#include <bits/stdc++.h>
#define lsb(x) x & -x
using namespace std;

const int N = 100005;

int n;
int fwk[N];

void update(int val)
{
    for (; val <= N; val += lsb(val))
    {
        fwk[val]++;
    }
}

int query(int k)
{
    int res = 0;
    for (; k > 0; k -= lsb(k))
    {
        res += fwk[k];
    }

    return res;
}

int main()
{
    scanf("%d", &n);

    int a;
    while (n--)
    {
        scanf("%d", &a);

        printf("%d ", query(a));
        update(a);
    }

    return 0;
}