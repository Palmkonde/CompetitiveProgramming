#include <bits/stdc++.h>
#define lsb(x) x & -x
using namespace std;

const int N = 200005;

int n, m, a, b, c;
int fwk[N];

void update(int pos, int val)
{
    for (; pos <= n; pos += lsb(pos))
    {
        fwk[pos] += val;
    }
}

int sum(int k)
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
    scanf("%d %d", &n, &m);

    while (m--)
    {
        scanf("%d%d%d", &a, &b, &c);

        if (a == 1)
        {
            update(c, b);
        }
        else
        {
            printf("%d\n", sum(c) - sum(b - 1));
        }
    }

    return 0;
}