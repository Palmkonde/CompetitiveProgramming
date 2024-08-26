#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;
string ori, ss;

vector<int> v;

int main()
{
    scanf("%d", &n);
    cin >> ori;

    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            v.push_back(i);
        }
    }

    ss = ori + ori;

    for (auto e : v)
    {
        if (ori == ss.substr(e, n))
        {
            cout << e;
            return 0;
        }
    }

    return 0;
}
