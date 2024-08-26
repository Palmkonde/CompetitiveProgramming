#include <bits/stdc++.h>
using namespace std;

uint64_t n, m;
int arr[100002];

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    uint64_t l = 0, r = ULLONG_MAX;

    while (l < r)
    {
        uint64_t mid = l + (r - l) / 2;
        uint64_t sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += mid / arr[i];
        }

        cout << mid << " " << sum << "\n";

        if (m <= sum)
        {
            r = mid;
        }
        else
            l = mid + 1;
    }

    cout << l;

    return 0;
}
/*
7 21
3
8
3
6
9
2
4

*/