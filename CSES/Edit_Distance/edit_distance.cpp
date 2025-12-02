#include <bits/stdc++.h>
using namespace std;

const int N = 5005;

int dp[N][N]; // minimum distance from s1[...i] to s2[...j]
string s1, s2;

int main() {
  cin.tie(NULL)->sync_with_stdio(false);
  cin >> s1 >> s2;

  for (int i = 0; i < N; i++) {
    fill(dp[i], dp[i] + N, INT_MAX);
  }

  for (int i = 0; i <= s1.size(); i++)
    dp[i][0] = i;
  for (int i = 0; i <= s2.size(); i++)
    dp[0][i] = i;

  for (int i = 1; i <= s1.size(); i++) {
    for (int j = 1; j <= s2.size(); j++) {
      dp[i][j] = min({dp[i - 1][j] + 1, dp[i][j - 1] + 1,
                      dp[i - 1][j - 1] + (s1[i - 1] != s2[j - 1])});
    }
  }

  cout << dp[s1.size()][s2.size()];
  return 0;
}
