#include <vector>
#include <bits/stdc++.h>
#include "stairs.h"
using namespace std;

const int K = 100005;
const int MOD = 1e9 + 7;

int dp[K];

int countWays(int N, int M, std::vector<int> S)
{

    dp[0] = 1;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (i - S[j] >= 0)
            {
                dp[i] += dp[i - S[j]];
                dp[i] %= MOD;
            }
        }
    }

    // printf("%d", dp[N]);
    return dp[N];
}

// int main()
// {
//     countWays(5, 2, {1, 2});
// }
// g++ -std=c++17 -O2 -o stairs grader.cpp stairs.cpp