#include <bits/stdc++.h>
using namespace std;

int a, b;
string temp;
int64_t tt;

int64_t convertFrom(int base)
{
    reverse(temp.begin(), temp.end());

    int64_t ans = 0;

    int power = 1;

    for (int i = 0; i < temp.size(); i++)
    {
        ans += (temp[i] - '0') * power;
        power *= base;
    }

    return ans;
}

void con(int base, int64_t N)
{
    if (N == 0)
    {
        return;
    }

    int x = N % base;
    N /= base;

    if (x < 0)
    {
        N += 1;
    }

    con(base, N);

    if (x < 0)
    {
        cout << x + (base * -1);
    }
    else
    {
        cout << x;
    }
}

int main()
{
    // cin.tie(NULL)->sync_with_stdio(false);

    cin >> a >> b;
    cin >> temp;

    tt = convertFrom(a);

    con(b, tt);

    return 0;
}