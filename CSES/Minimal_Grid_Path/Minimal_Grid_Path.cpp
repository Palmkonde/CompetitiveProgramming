#include <bits/stdc++.h>
using namespace std;

const int N = 3005;
const int INF = 1e9;

struct Cell {
  int r, c;
  char letter;
  int next_rank;

  bool operator<(const Cell &other) const {
    if (this->letter != other.letter)
      return this->letter < other.letter;
    return this->next_rank < other.next_rank;
  }

  bool operator==(const Cell &other) const {
    return letter == other.letter && next_rank == other.next_rank;
  }
};

int n;

// dp[i][j] means rank when consider sorting with same diagonals of cell(i, j)
// using this to rank each the same distance for selection
int dp[N][N];
char grid[N][N];

// Global buffers to avoid memory allocation overhead in the loop
Cell buffer[N];
int cnt[N + 5]; // Max rank is N, so N+5 is plenty
int INF_RANK;

void radix_sort(vector<Cell> &cells) {
  int len = cells.size();
  if (len <= 1)
    return;

  // --- PASS 1: Sort by next_rank (Secondary Key) ---
  // Range of next_rank is [0, INF_RANK]

  // 1. Reset count array
  // We only need to clear up to the max possible value we used
  for (int i = 0; i <= INF_RANK; i++)
    cnt[i] = 0;

  // 2. Count frequencies
  for (const auto &cell : cells) {
    cnt[cell.next_rank]++;
  }

  // 3. Compute prefix sums (positions)
  for (int i = 1; i <= INF_RANK; i++) {
    cnt[i] += cnt[i - 1];
  }

  // 4. Build output (Iterate BACKWARDS to maintain stability)
  for (int i = len - 1; i >= 0; i--) {
    buffer[--cnt[cells[i].next_rank]] = cells[i];
  }

  // Copy back to original vector
  for (int i = 0; i < len; i++)
    cells[i] = buffer[i];

  // --- PASS 2: Sort by letter (Primary Key) ---
  // Range of char is usually 0-127 (ASCII)

  // 1. Reset count array (size 128 is enough for ASCII)
  for (int i = 0; i < 128; i++)
    cnt[i] = 0;

  // 2. Count frequencies
  for (const auto &cell : cells) {
    cnt[cell.letter]++;
  }

  // 3. Compute prefix sums
  for (int i = 1; i < 128; i++) {
    cnt[i] += cnt[i - 1];
  }

  // 4. Build output (Iterate BACKWARDS)
  for (int i = len - 1; i >= 0; i--) {
    buffer[--cnt[cells[i].letter]] = cells[i];
  }

  // Copy back
  for (int i = 0; i < len; i++)
    cells[i] = buffer[i];
}

int main() {

  cin.tie(NULL)->sync_with_stdio(false);
  cin >> n;

  INF_RANK = n + 1;
  for (int i = 0; i < N; i++) {
    fill(dp[i], dp[i] + N, INF_RANK);
  }

  for (int i = 1; i <= n; i++) {
    string tmp;
    cin >> tmp;
    for (int j = 1, k = 0; j <= n; j++, k++) {
      grid[i][j] = tmp[k];
    }
  }

  dp[n][n] = 0;
  int start_i, end_i, j;

  // diagonal_d
  for (int d = 2 * n; d >= 2; d--) {
    vector<Cell> diagonals_cell;

    start_i = max(1, d - n);
    end_i = min(n, d - 1);

    for (int i = start_i; i <= end_i; i++) {
      j = d - i;

      // printf("i: %d, j: %d min_value: %d\n", i, j,
      //        min({dp[i + 1][j], dp[i][j + 1], dp[i][j]}));
      int rank_down = (i + 1 <= n) ? dp[i + 1][j] : INF_RANK;
      int rank_right = (j + 1 <= n) ? dp[i][j + 1] : INF_RANK;

      int best_next = min(rank_down, rank_right);

      diagonals_cell.push_back({i, j, grid[i][j], best_next});
    }
    radix_sort(diagonals_cell);

    int current_rank = 0;
    for (int i = 0; i < diagonals_cell.size(); i++) {
      if (i > 0 && !(diagonals_cell[i] == diagonals_cell[i - 1])) {
        current_rank++;
      }

      auto [r, c, letter, next_rank] = diagonals_cell[i];
      // printf("r: %d, c: %d rank: %d\n", r, c, current_rank);
      dp[r][c] = current_rank;
    }
  }

  pair<int, int> pos = {1, 1};

  while (pos != make_pair(n, n)) {
    cout << grid[pos.first][pos.second];

    int r = pos.first;
    int c = pos.second;

    int r_down = (r + 1 <= n) ? dp[r + 1][c] : INF_RANK;
    int r_right = (c + 1 <= n) ? dp[r][c + 1] : INF_RANK;

    if (r_down < r_right) {
      pos = {r + 1, c};
    } else {
      pos = {r, c + 1};
    }
  }
  cout << grid[n][n];
  cout << "\n";

  return 0;
}
