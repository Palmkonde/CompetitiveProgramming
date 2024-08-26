#include <bits/stdc++.h>
using namespace std;

int n;
char t;
stack<char> c;

int main()
{
    cin.tie()->sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> t;

        if (c.empty())
        {
            c.push(t);
        }
        else
        {
            if (c.top() == t)
            {
                c.pop();
            }
            else
            {
                c.push(t);
            }
        }
    }

    if (c.size() != 0)
    {
        cout << c.size() << "\n";
        while (not c.empty())
        {
            cout << c.top();
            c.pop();
        }
    }
    else
    {
        cout << 0 << "\n"
             << "empty";
    }

    return 0;
}