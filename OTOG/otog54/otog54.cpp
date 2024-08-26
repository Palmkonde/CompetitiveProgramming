#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> L;

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> n;

    while (n--)
    {
        int x;
        cin >> x;

        if (L.empty())
        {
            L.push_back(x);
        }

        if (L.back() < x)
        {
            L.push_back(x);
        }

        else
        {
            auto it = lower_bound(L.begin(), L.end(), x);
            int idx = it - L.begin();
            L[idx] = x;
        }
    }

    cout << L.size();

    return 0;
}