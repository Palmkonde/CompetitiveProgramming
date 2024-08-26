#include <vector>
#include <bits/stdc++.h>
#include "archery.h"
using namespace std;
using ll = long long;

const int K = 305;

long long minPenguinCoin(int N, std::vector<int> A, std::vector<int> U, std::vector<int> D)
{
    ll res = INT_MAX;

    for (int i = 0; i < N; i++)
    {
        ll tmp = 0;
        for (int j = 0; j < N; j++)
        {
            tmp += abs(A[i] - A[j]);
        }

        res = min(res, tmp);
    }

    return res;
}

// int main()
// {
//     cout << minPenguinCoin(5, {6, 2, 1, 3, 5}, {0, 0, 0, 0}, {0, 0, 0, 0});
// }