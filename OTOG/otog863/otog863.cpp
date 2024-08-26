#include <bits/stdc++.h>
using namespace std;
int n;
vector<string> s;
string tmp;

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        s.push_back(tmp);
    }

    int idx = 0;
    vector<string> ans;
    string tt;
    for (int i = 1; i < 2 * n; i++)
    {
        cin >> tmp;

        if (tmp == "SHIFT")
        {
            ans.push_back(s[idx++]);
        }

        else if (tmp == "RIGHT")
        {
            tt = ans.back();
            ans.pop_back();
            ans.pop_back();
            ans.push_back(tt);
        }

        else if (tmp == "LEFT")
        {
            ans.pop_back();
        }
    }

    cout << ans[0];

    return 0;
}