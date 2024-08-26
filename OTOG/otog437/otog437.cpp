#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll bitExp(int a, int b, int c)
{
    ll ans = 1;

    while (b)
    {
        if (b & 1)
        {
            ans = (ans * (ll)a) % c;
        }
        a = ((ll)a * (ll)a) % c;
        b >>= 1;
    }

    return ans;
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int a, b, c;
    while (cin >> a >> b >> c)
    {
        cout << bitExp(a, b, c) << "\n";
    }

    return 0;
}