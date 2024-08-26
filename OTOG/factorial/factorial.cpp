#include <bits/stdc++.h>
using namespace std;

int n;
int res[1000000];

void fac(int n)
{
    int size = 1;
    memset(res, 0, sizeof(res));
    res[0] = 1;

    for (int i = 2; i <= n; i++)
    {
        int carry = 0;
        for (int j = 0; j < size; j++)
        {
            int product = res[j] * i + carry;
            res[j] = product % 10;
            carry = product / 10;
        }
        while (carry)
        {
            res[size] = carry % 10;
            carry /= 10;
            size++;
        }
    }

    for (int i = size - 1; i >= 0; --i)
    {
        cout << res[i];
    }
    cout << "\n";
}

int main()
{
    while (cin >> n)
    {
        fac(n);
    }

    return 0;
}