#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll cnt = 1, mx = 1;
string s;

int main() {
  cin >> s;

  char cur;
  char last;

  for (int i = 0; i < s.size(); i++) {

    cur = s[i];

    if (!i) {
      goto skip;
    }

    if (cur != last) {
      cnt = 1;
    } else if (cur == last) {
      cnt++;
    }
    mx = max(mx, cnt);

  skip:
    last = s[i];
  }

  cout << mx;
  return 0;
}
