#include <bits/stdc++.h>
using namespace std;

string s;

pair<string, int> div(string tmp, int a)
{
    string ans = "";
    int num = tmp[0] - '0', rem = 0;
    int idx = 0;

    while (num < a)
    {
        num = num * 10 + (tmp[++idx] - '0');
    }

    for (; idx < tmp.size();)
    {
        ans += to_string(num / a);
        rem = num % a;
        num = (rem * 10) + (tmp[++idx] - '0');
    }

    return make_pair(ans, rem);
}

void converter(string tmp, int dow)
{
    cout << dow << ": ";

    string ans = "";
    pair<string, int> tmp2 = div(tmp, dow);

    do
    {
        tmp2 = div(tmp, dow);
        ans += to_string(tmp2.second);
        tmp = tmp2.first;
    } while (tmp != "0");

    reverse(ans.begin(), ans.end());

    cout << ans << "\n";
}

int main()

{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> s;

    for (int i = 2; i <= 9; i++)
    {
        converter(s, i);
    }

    return 0;
}