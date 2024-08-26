#include <bits/stdc++.h>
#define lsb(x) x & -x
using namespace std;

const int N = 100005;

int n, m;
int fwk[N];

void upd(int k)
{
    for (; k <= N; k += lsb(k))
    {
        fwk[k]++;
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
    scanf("%d%d", &n, &m);

    int tmp;
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &tmp);
        upd(tmp);
    }

    n -= m;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        printf("%d\n", sum(tmp) + 1);
        upd(tmp);
    }

    return 0;
}