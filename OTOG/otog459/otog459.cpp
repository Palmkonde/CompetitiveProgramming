#include <bits/stdc++.h>
using namespace std;

string mounth[] = {"DEC", "JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV"};
map<string, int> mp = {
    {"JAN", 1},
    {"FEB", 2},
    {"MAR", 3},
    {"APR", 4},
    {"MAY", 5},
    {"JUN", 6},
    {"JUL", 7},
    {"AUG", 8},
    {"SEP", 9},
    {"OCT", 10},
    {"NOV", 11},
    {"DEC", 12}};

string tmp;
int n;

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> tmp >> n;

    int m = mp[tmp];

    m += n;
    m %= 12;

    // cout << m << " " << 12 + m << "\n";
    if (m < 0)
    {
        cout << mounth[12 + m];
    }

    else
        cout << mounth[m];

    return 0;
}