#include <bits/stdc++.h>
using namespace std;

int n;
char c[105];
string buff;

int main()
{
    cin >> n;

    getline(cin, buff, '\n');

    while (n--)
    {
        getline(cin, buff, '\n');

        int l = 0, u = 0;
        buff += " ";
        int sum = 0;

        for (auto e : buff)
        {
            if (e == ' ')
            {

                if (l == 0 and u != 0)
                {
                    sum += 1;
                }

                else if (l != 0 and u == 0)
                {
                    sum += 2;
                }
                else if (l != 0 and u != 0)
                {
                    sum += 3;
                }
                l = u = 0;
                continue;
            }

            if (islower(e))
            {
                l++;
            }
            if (isupper(e))
            {
                u++;
            }
        }

        cout << sum << "\n";
    }

    return 0;
}