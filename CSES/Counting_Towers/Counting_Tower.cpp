#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;
const int maxN = 1e6;

ll n, t;
ll dp[N][2];

/*
 * dp[i][0] = i_th block is block type a
 * dp[i][1] = i_th block is block type b
 *
 * type a seperate
 * |_||_|
 *
 * type b  connected
 * |__|
 */

int main() {
  cin >> t;

  dp[1][0] = dp[1][1] = 1;
  for (int i = 2; i <= maxN; i++) {
    dp[i][0] = (dp[i - 1][0] * 4 % MOD + dp[i - 1][1]) % MOD;
    dp[i][1] = (dp[i - 1][0] + dp[i - 1][1] * 2 % MOD) % MOD;
  }

  while (t--) {
    int q;
    cin >> q;
    cout << (dp[q][0] + dp[q][1]) % MOD << "\n";
  }
}
