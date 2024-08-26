#include <bits/stdc++.h>
using namespace std;

int n;

void line(int l, int a)
{
    int tm = 1;

    for (int j = 0; j < a; j++)
    {
        cout << " ";
    }

    for (int i = 0; i < l; i++)
    {

        if (tm)
        {
            cout << "*";
            tm = 0;
        }
        else
        {
            cout << "^";
            tm = 1;
        }
    }
}

int main()
{

    cin >> n;

    for (int i = 0; i < n / 2; i++)
    {
        line((2 * i) + 1, (n / 2) - i);
        cout << "\n";
    }

    int tm = 1;
    for (int i = 0; i < n; i++)
    {
        if (i == (n / 2))
        {
            cout << "N";
            tm = !tm;
            continue;
        }

        if (tm)
        {
            cout << "*";
            tm = 0;
        }
        else
        {
            cout << "^";
            tm = 1;
        }
    }

    cout << "\n";
    int mixer = 1;
    for (int i = n - 2; i >= 0; i -= 2)
    {
        line(i, mixer++);
        cout << "\n";
    }

    return 0;
}
