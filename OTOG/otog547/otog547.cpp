#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a, b;

    while (cin >> a >> b)
    {
        int as = a.size(), bs = b.size(), cnt = 0;
        for (int i = 0; i < as; i++)
        {
            if (i + bs > as)
            {
                break;
            }
            string temp = a.substr(i, bs);

            if (temp == b)
            {
                cnt++;
            }
        }
        cout << cnt << "\n";
    }

    return 0;
}