#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, k;
vector<int> v;
int L[N];

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> n;

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        v.push_back(k);
    }

    for (int i = 0; i < n; i++)
    {
        int idx = upper_bound(L, L + ans + 1, v[i]) - L;
        ans = max(idx, ans);
        L[idx] = v[i];
    }

    cout << ans;

    return 0;
}