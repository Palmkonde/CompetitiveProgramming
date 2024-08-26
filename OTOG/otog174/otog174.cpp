#include <bits/stdc++.h>
using namespace std;

int n;
string a;

void recur(int l, int r)
{
    if (l >= r)
        return;

    int mid = l + (r - l) / 2;
    reverse(a.begin() + l, a.begin() + r + 1);
    recur(l, mid);
    recur(mid + 1, r);
}

int main()
{
    cin >> n;
    cin >> a;

    recur(0, n - 1);
    cout << a;
    return 0;
}