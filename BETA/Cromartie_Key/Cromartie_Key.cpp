#include <bits/stdc++.h>
using namespace std;

int l, k;
string m1, m2, key;

char mid(char a, char b, char c)
{
    int mx = max(a, max(b, c));
    int mn = min(a, min(b, c));

    return (char)((a + b + c) - (mx + mn));
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> l >> k;

    cin >> m1 >> m2;
    cin >> key;

    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < k; j++)
        {
            key[j] = mid(m1[i], m2[i], key[j]);
        }
    }

    cout << key;

    return 0;
}