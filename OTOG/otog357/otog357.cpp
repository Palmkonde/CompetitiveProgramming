#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e7 + 5;

ll a, b, aa, bb;
bool f[N];

bool isPrime(ll x)
{
    if (x <= 1)
        return false;
    for (ll i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

int main()
{
    ll cnt = 0;
    scanf("%lld %lld", &aa, &bb);

    f[1] = true;
    for (int i = 2; i < N / 2; i++)
    {
        if (f[i])
            continue;
        for (int j = 2 * i; j < N; j += i)
        {
            f[j] = true;
        }
    }

    a = min(aa, bb);
    b = max(aa, bb);

    for (ll i = a; i <= b; i++)
    {
        if (i < N)
        {
            cnt += (!f[i]);
        }
        else
        {
            cnt += isPrime(i);
        }
    }

    printf("%lld", cnt);
    return 0;
}