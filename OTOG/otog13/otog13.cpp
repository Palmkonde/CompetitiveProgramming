#include <bits/stdc++.h>
using namespace std;

int t;

int main()
{
    cin >> t;

    while (t--)
    {
        int f = 0;
        int b = 1000005;
        int x;
        cin >> x;
        while (x--)
        {

            int a, c;
            cin >> a >> c;
            f = max(a, f);
            b = min(c, b);
        }

        if (f <= b)
            cout << "no";
        else
            cout << "yes";

        cout << "\n";
    }
    return 0;
}