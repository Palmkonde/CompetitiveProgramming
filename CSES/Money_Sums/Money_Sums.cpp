#include <bits/stdc++.h>
using namespace std;

const int N = 105;
const int M = 100005;

int n, x;
int coin[N];

// int dp[N][M]; // dp[1..i][S] = from c_1 to c_n coins can be sum to S
int dp[M]; // transitive i since i using only i - 1

int main() {
  cin.tie(NULL)->sync_with_stdio(false);

  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> coin[i];
  }

  // -----------------------------------------------------------------------------------
  // int cnt = 0;
  // for (int i = 1; i <= n; i++) {
  //   for (int j = 0; j <= M - 5; j++) {
  //     if (j == 0 || j == coin[i]) {
  //       dp[i][j] = 1;
  //       continue;
  //     }
  //
  //     dp[i][j] = dp[i - 1][j] || ((j >= coin[i]) ? dp[i - 1][j - coin[i]] :
  //     0);
  //   }
  // }
  // for (int i = 1; i <= M - 5; i++) {
  //   if (dp[n][i])
  //     cnt++;
  // }
  //
  // cout << cnt << "\n";
  // for (int i = 1; i <= M - 5; i++) {
  //   if (dp[n][i])
  //     cout << i << " ";
  // }
  // -----------------------------------------------------------------------------------

  dp[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = M - 5; j >= 0; j--) {
      dp[j] = dp[j] || ((j >= coin[i]) ? dp[j - coin[i]] : 0);
    }
  }

  int cnt = 0;
  for (int i = 1; i <= M - 5; i++) {
    cnt += dp[i];
  }
  cout << cnt << "\n";

  for (int i = 1; i <= M - 5; i++) {
    if (dp[i])
      cout << i << " ";
  }
  return 0;
}
