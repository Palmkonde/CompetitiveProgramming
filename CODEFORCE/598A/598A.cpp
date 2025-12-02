#include <bits/stdc++.h>
#include <cmath>
using namespace std;
using ll = long long;

ll n, t;

int main() {
  cin.tie(NULL)->sync_with_stdio(false);
  cin >> t;

  // Time complexity tlg(n)
  while (t--) {
    cin >> n;

    ll sum = (n * (n + 1)) / 2;
    ll tmp = (1 << int(floor(log2(n))));

    while (tmp > 0) {
      sum -= 2 * tmp;
      tmp >>= 1;
    }

    cout << sum << "\n";
  }
  return 0;
}
