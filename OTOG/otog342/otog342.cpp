#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, l, r;
int num[N];

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    cin >> l >> r;

    sort(num, num + n);

    int ans = 0;
    int idx = 0;

    for (int i = l; i <= r; i++)
    {
        int mn = INT_MIN;
        auto it = lower_bound(num, num + n, i);
    }

    cout << idx;
    return 0;
}