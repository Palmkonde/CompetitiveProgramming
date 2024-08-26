#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int N = 50005;

int n, m, a, b, t, temp = 0, ans = 0;
vector<pii> s;

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        s.push_back({a + 1, 1});
        s.push_back({b, -1});
    }

    for (int i = 0; i < m; i++)
    {
        cin >> t;
        s.push_back({t, 99});
    }

    sort(s.begin(), s.end());

    for (auto it = s.begin(); it != s.end(); ++it)
    {

        if (it->second == 99)
        {
            ans += temp;
            continue;
        }

        temp += it->second;
    }

    cout << ans % 2007;

    return 0;
}