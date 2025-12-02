#include <bits/stdc++.h>
#include <climits>
using namespace std;

const int N = 505;

// (5, 6) greedy 5, dp 4
// dp[a][b] = minimum move for rectangle size a x b
int dp[N][N];
int recur(int a, int b) {
  if (a == b)
    return 0;

  if (dp[a][b] != INT_MAX)
    return dp[a][b];

  int res = INT_MAX;
  for (int k = 1; k < a; k++) {
    res = min(1 + recur(k, b) + recur(a - k, b), res);
  }

  for (int k = 1; k < b; k++) {
    res = min(1 + recur(a, k) + recur(a, b - k), res);
  }

  return dp[a][b] = res;
}

int a, b;
int main() {
  for (int i = 0; i < N; i++) {
    fill(dp[i], dp[i] + N, INT_MAX);
  }
  cin >> a >> b;

  for (int i = 1; i <= a; i++) {
    for (int j = 1; j <= b; j++) {
      if (i == j) {
        dp[i][j] = 0;
        continue;
      }
      for (int k = 1; k < i; k++) {
        dp[i][j] = min(dp[i][j], 1 + dp[k][j] + dp[i - k][j]);
      }

      for (int k = 1; k < j; k++) {
        dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[i][j - k]);
      }
    }
  }

  cout << dp[a][b];

  return 0;
}
