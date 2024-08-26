#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

set<string> ss;
string tmp, last;
int n;

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        ss.insert(tmp);
    }

    int sz = ss.size();

    cout << sz << "\n";

    for (auto it = ss.begin(); it != ss.end(); it++)
    {
        tmp = *it;

        if (tmp.substr(0, 3) == last.substr(0, 3))
        {
            continue;
        }

        cout << *it << " ";
        last = tmp;
    }

    return 0;
}