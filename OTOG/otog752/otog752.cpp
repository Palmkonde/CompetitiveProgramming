#include <bits/stdc++.h>
using namespace std;

int n, q;
int num[100005];
int64_t prefix[100005];

vector<pair<int64_t, int>> v;

int lw(int l, int r, int64_t x)
{
    while (l < r)
    {
        int mid = l + (r - l) / 2;

        if (x <= v[mid].first)
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }

    if (l == v.size())
    {
        return -1;
    }

    else
        return v[l].second;
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    prefix[0] = num[0];
    v.push_back({num[0], 0});
    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + num[i];

        if (prefix[i] > v.back().first)
        {
            v.push_back({prefix[i], i});
        }
    }

    int k;
    while (q--)
    {
        cin >> k;
        auto it = lw(0, v.size(), k);

        cout << it << "\n";
    }

    return 0;
}