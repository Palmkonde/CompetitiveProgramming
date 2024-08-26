#include <bits/stdc++.h>
using namespace std;

vector<string> ans;
int n;

void solve(int l, int r, string tmp)
{
    if (tmp.size() == 2 * n)
    {
        ans.push_back(tmp);
        return;
    }
    if (l == 0 and r == 0)
        return;

    if (l > 0)
    {
        solve(l - 1, r, tmp + '(');
    }

    if (r > l)
    {
        solve(l, r - 1, tmp + ')');
    }
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> n;

    solve(n, n, "");

    cout << ans.size() << "\n";
    for (auto e : ans)
    {
        cout << e << "\n";
    }
    return 0;
}