#include <bits/stdc++.h>
using namespace std;

string a, b;

int main()
{
    cin >> a >> b;

    for (int len = a.size(); len > 0; len--)
    {
        for (int pos = 0; pos < a.size() - len + 1; pos++)
        {
            if (b.find(a.substr(pos, len)) != string::npos)
            {
                cout << a.substr(pos, len);
                return 0;
            }
        }
    }

    return 0;
}