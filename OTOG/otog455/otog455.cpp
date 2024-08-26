#include <bits/stdc++.h>
using namespace std;

int q;
string t[5];

int main()
{
    scanf("%d", &q);

    int s;
    while (q--)
    {
        s = 0;
        int tmp = 0;
        int fg = 0;
        for (int i = 0; i < 5; i++)
        {
            cin >> t[i];
        }

        for (int i = 0; i < 5; i++)
        {

            if (t[i] == "J" or t[i] == "Q" or t[i] == "K")
            {
                tmp = 10;
            }

            else if (t[i] == "A")
            {
                tmp = 1;
            }

            else
            {
                tmp = stoi(t[i]);
            }

            s += tmp;

            if (s > 16)
            {
                if (s > 21)
                {
                    printf("busted\n");
                    fg = 1;
                    break;
                }
                else
                {
                    printf("%d\n", s);
                    fg = 1;
                    break;
                }
            }
        }

        if (s <= 21 and !fg)
        {
            printf("%d\n", s);
        }
    }

    return 0;
}