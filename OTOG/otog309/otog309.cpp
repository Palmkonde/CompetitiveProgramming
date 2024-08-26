#include <bits/stdc++.h>
using namespace std;

int n;
int num[100005];

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    int total = 0;
    int bp1 = 0;
    int bp2 = 0;
    int maxSum = INT_MIN;
    int minSum = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        total += num[i];
        bp1 = max(bp1 + num[i], num[i]);
        bp2 = min(bp2 + num[i], num[i]);

        maxSum = max(bp1, maxSum);
        minSum = min(bp2, minSum);
    }

    if (maxSum > 0)
    {
        cout << max(maxSum, total - minSum);
    }

    else
        cout << maxSum;

    return 0;
}