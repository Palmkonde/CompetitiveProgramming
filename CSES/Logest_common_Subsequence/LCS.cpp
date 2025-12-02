#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;

const int N = 1005;

int a[N], b[N];
int n, m;

int dp[N][N];
vector<int> path;

int main() {
  cin.tie(NULL)->sync_with_stdio(false);
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int i = 1; i <= m; i++) {
    cin >> b[i];
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

      if (a[i] == b[j]) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
      }
    }
  }

  cout << dp[n][m] << "\n";

  int cur = dp[n][m];
  int i = n, j = m;
  while (cur > 0) {
    while (dp[i - 1][j] == cur) {
      i--;
    }

    while (dp[i][j - 1] == cur) {
      j--;
    }

    path.push_back(a[i]);
    i--, j--, cur--;
  }

  reverse(all(path));

  for (auto &e : path)
    cout << e << " ";
  return 0;
}
