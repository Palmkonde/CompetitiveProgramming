#include <bits/stdc++.h>
using namespace std;
using TUPLE = tuple<char, char, int>;

int n;
vector<TUPLE> v;

int main()
{
    cin >> n;

    char a, c;
    int b;
    for (int i = 0; i < n; i++)
    {
        scanf(" %c", &a);
        if (a == 'T')
        {
            scanf(" %c", &c);
        }
        else
        {
            scanf("%d", &b);
        }
        v.push_back({a, b, c});
    }

    reverse(v.begin(), v.end());

    for (auto it = v.begin(); it != v.end(); it++)
    {
        tie(a, b, c) = *it;

        if (a == 'T')
        {
            cout << c;
        }
        else
        {
            it += b;
        }
    }

    return 0;
}