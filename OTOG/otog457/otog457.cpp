#include <bits/stdc++.h>
using namespace std;

string s;

int main()
{
    int cnt = 0;
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> s;

    for (auto e : s)
    {
        if (e == '0' or e == '6' or e == '4' or e == '9' or e == '8')
            cnt++;

        if (e == '8')
            cnt++;
    }

    cout << cnt;

    return 0;
}