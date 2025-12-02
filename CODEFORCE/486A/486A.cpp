#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n;

int main() {
  cin >> n;
  ll res = floor((double)(n + 1) / 2) * pow(-1, n & 1);
  cout << res;

  return 0;
}
