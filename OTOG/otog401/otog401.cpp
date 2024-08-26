#include <bits/stdc++.h>
using namespace std;

string n;
int m;

int main()
{
    cin >> n >> m;

    int temp, r = 0;

    for (int i = 0; i < n.size(); i++)
    {
        temp = r * 10 + (n[i] - '0');
        r = temp % m;
    }

    cout << r;

    return 0;
}