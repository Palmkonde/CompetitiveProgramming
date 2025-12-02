#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t, a, b;

int main() {
  cin >> t;

  while (t--) {
    cin >> a >> b;

    ll x, q;
    q = ceil(double(a) / double(b));
    x = b * q - a;

    // printf("%lld %lld %lld %lld \n", a, b, q, x);
    cout << x << "\n";
  }
  return 0;
}
