#include <bits/stdc++.h>
using namespace std;

const string pad[9] = {"", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};
const int mod[] = {0, 3, 3, 3, 3, 3, 4, 3, 4};
string ans;

void pass(int btn, int n)
{
    if (btn == 0)
    {
        while (n--)
        {
            if (!ans.empty())
            {
                ans.pop_back();
            }
        }
    }
    else
    {
        ans.push_back(pad[btn][(n - 1) % mod[btn]]);
    }
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int h, v, m, s, n;
    cin >> n >> s >> m;
    pass(s - 1, m);

    for (int i = 1; i < n; i++)
    {
        cin >> h >> v >> m;
        s += (v * 3) + h;
        pass(s - 1, m);
    }

    if (ans.empty())
    {
        cout << "null";
    }
    else
    {
        cout << ans;
    }

    return 0;
}