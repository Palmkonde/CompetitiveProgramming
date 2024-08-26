#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> n;

    string x;
    while (n--)
    {
        int top = 1, f = 2, l = 3, r = 4, b = 5, bot = 6;
        cin >> x;

        for (int i = 0; i < x.size(); i++)
        {
            int t1 = top, t2 = f, t3 = l, t4 = r, t5 = b, t6 = bot;
            if (x[i] == 'F')
            {
                top = t5;
                f = t1;
                b = t6;
                bot = t2;
            }
            else if (x[i] == 'B')
            {
                top = t2;
                f = t6;
                b = t1;
                bot = t5;
            }
            else if (x[i] == 'L')
            {
                top = t4;
                l = t1;
                r = t6;
                bot = t3;
            }
            else if (x[i] == 'R')
            {
                top = t3;
                l = t6;
                r = t1;
                bot = t4;
            }
            else if (x[i] == 'C')
            {
                f = t4;
                l = t2;
                b = t3;
                r = t5;
            }
            else if (x[i] == 'D')
            {
                f = t3;
                l = t5;
                b = t4;
                r = t2;
            }
        }
        cout << f << " ";
    }

    return 0;
}