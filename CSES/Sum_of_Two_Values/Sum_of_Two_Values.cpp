#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, x;
vector<pair<int64_t, int>> arr(N);

int main()
{
    scanf("%d%d", &n, &x);

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i].first);
        arr[i].second = i;
    }

    int l = 1, r = n;
    int64_t sum = 0;

    sort(arr.begin(), arr.begin() + n + 1);

    while (l < r)
    {
        sum = arr[l].first + arr[r].first;

        if (sum > x)
            r--;
        else if (sum < x)
            l++;

        else if (sum == x)
        {
            printf("%d %d", arr[l].second, arr[r].second);
            return 0;
        }
    }

    printf("IMPOSSIBLE");

    return 0;
}