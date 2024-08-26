#include <bits/stdc++.h>
using namespace std;

vector<string> v;
string c;
int n;

bool cmp(string a, string b)
{
    return stod(a) < stod(b);
}

int main()
{

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> c;
        v.push_back(c);
    }

    sort(v.begin(), v.end(), cmp);

    for (auto e : v)
    {
        cout << e << "\n";
    }

    return 0;
}