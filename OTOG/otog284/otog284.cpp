#include <bits/stdc++.h>
using namespace std;

int n, x;
vector<int> a, b;
map<int, int> aa, bb;
bool c[50005];

int main()
{
    // cin.tie(NULL)->sync_with_stdio(false);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        a.push_back(x);
    }

    for (int j = 0; j < n; j++)
    {
        cin >> x;

        if (bb[x] == 0)
        {
            b.push_back(x);
        }

        bb[x]++;
    }

    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end());

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        auto it = upper_bound(b.begin(), b.end(), a[i]);

        it--;
        if (it == b.begin() - 1)
            continue;

        while (*it == a[i])
        {
            it--;
        }

        if (it == b.begin() - 1)
            continue;

        if (*it < a[i] and bb[*it] != 0)
        {
            ans += a[i];
            bb[*it]--;

            if (bb[*it] == 0)
            {
                b.erase(it);
            }
        }
        // cout << *it << " " << ans << "\n";
    }

    cout << ans;
    return 0;
}