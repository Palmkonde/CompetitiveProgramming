#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e6 + 5;

ll n, m, s;
ll arr[N], mark[N];

int main()
{
    scanf("%lld %lld %lld", &n, &m, &s);
    memset(mark, -1, sizeof(mark));

    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &arr[i]);
    }

    ll now = s, end, c = 0;
    while (m)
    {
        // printf("%lld\n", m);
        if (mark[now] != -1)
        {
            m++;
            c -= mark[now];
            break;
        }

        end = now;
        mark[now] = c;

        now += arr[now];
        c++;
        m--;
    }

    if (m > 0)
    {
        m %= c;
        now = end;
    }

    while (m)
    {
        now += arr[now];
        m--;
    }

    printf("%lld", now);

    return 0;
}

/*
7 18 2
3 4 -2 3 -2 -1 -2
*/