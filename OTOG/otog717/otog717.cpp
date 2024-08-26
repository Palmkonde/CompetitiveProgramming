#include <bits/stdc++.h>
using namespace std;

int q, a;
vector<int> ans, backlist;

bool isPrime(int x)
{
    if (x <= 1)
    {
        return false;
    }

    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> q;
    while (q--)
    {
        cin >> a;

        ans.push_back(1);

        if (isPrime(a))
        {
            for (int i = 2; i < a; i++)
            {
                ans.push_back(i);
            }
            goto out;
        }

        for (int i = 2; i < a; i++)
        {
            if (a % i == 0)
            {
                if (isPrime(i))
                {
                    backlist.push_back(i);
                }
                continue;
            }

            int fg = 0;
            for (auto e : backlist)
            {
                if (i % e == 0)
                {
                    fg = 1;
                    break;
                }
            }

            if (fg)
                continue;

            else if (!fg)
            {
                ans.push_back(i);
            }
        }

    out:
        cout << ans.size() << "\n";
        for (auto e : ans)
        {
            cout << e << " ";
        }

        cout << "\n";
        ans.clear();
        backlist.clear();
    }

    return 0;
}