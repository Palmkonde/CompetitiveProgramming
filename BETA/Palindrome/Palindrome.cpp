#include <bits/stdc++.h>
using namespace std;

string n;

bool isPalin(string temp)
{
    string t = temp;
    reverse(t.begin(), t.end());

    if (temp == t)
        return true;
    else
        return false;
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n.size(); i++)
    {
        n[i] = tolower(n[i]);
    }

    if (isPalin(n))
    {
        if (isPalin(n.substr(0, n.size() / 2)))
        {
            cout << "Double Palindrome";
            return 0;
        }

        cout << "Palindrome";
        return 0;
    }
    else
        cout << "No";

    return 0;
}