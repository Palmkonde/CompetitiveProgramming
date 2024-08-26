#include <bits/stdc++.h>
using namespace std;

int n;
void A(int x, int end)
{
    if (x == end)
    {
        cout << "sin(" << x << ")";
        return;
    }

    (x % 2 == 1) ? cout << "sin(" << x << "-" : cout << "sin(" << x << "+";
    A(x + 1, end);
    cout << ")";
}

void S(int x)
{
    if (x == 1)
    {
        A(1, 1);
        cout << "+" << n;
        return;
    }

    cout << "(";
    S(x - 1);
    cout << ")";
    A(1, x);
    cout << "+" << (n - x) + 1;
}

int main()
{
    cin >> n;
    S(n);

    return 0;
}
