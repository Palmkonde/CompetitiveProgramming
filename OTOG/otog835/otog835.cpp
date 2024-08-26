#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

long long x;

int main()
{
    scanf("%lld", &x);

    x %= MOD;

    printf("%lld", x * x % MOD * x % MOD);

    return 0;
}