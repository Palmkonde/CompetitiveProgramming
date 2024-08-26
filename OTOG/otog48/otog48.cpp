#include <bits/stdc++.h>
using namespace std;

int n;
string b[100005];

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    sort(b, b + n, [](const string &a, const string &b)
         {
        if(a+b < b+a) return true; 
        else return false; });

    for (int i = 0; i < n; i++)
    {
        cout << b[i];
    }

    return 0;
}
// https://stackoverflow.com/questions/25396760/how-can-we-efficiently-find-the-minimum-integer-from-concatenating-integers-in-a