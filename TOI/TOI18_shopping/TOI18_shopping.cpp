#include <bits/stdc++.h>
using namespace std;

const int N = 500005;
int64_t score[N], cost[N], n, q, a;

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        if (a >= 0)
        {
            score[i] += a;
        }
        else
        {
            cost[i] -= a;
        }
        score[i] += score[i - 1];
        cost[i] += cost[i - 1];
    }

    int64_t idx, m;
    while (q--)
    {
        cin >> idx >> m;
        int id = lower_bound(cost + 1, cost + n + 1, m + cost[idx]) - (cost + 1);
        cout << score[id] - score[idx] << "\n";
    }

    return 0;
}

/*
10 1
-1 5 1 -4 6 -7 2 3 -7 -5
1 10
*/