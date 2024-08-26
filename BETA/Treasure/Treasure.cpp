#include <bits/stdc++.h>
using namespace std;

string s;
double x = 0, y = 0;

int main()
{

    while (1)
    {
        cin >> s;
        if (s == "*")
        {
            break;
        }

        string num;
        string di;

        for (char e : s)
        {
            if (e - '0' >= 0 and e - '0' <= 9)
            {
                num += e;
            }
            else
            {
                di += e;
            }
        }

        int t = stoi(num);
        double n = t * 1.0;
        if (di == "N")
        {
            y += n;
        }
        else if (di == "NE")
        {
            n = n / sqrt(2);
            x += n;
            y += n;
        }
        else if (di == "E")
        {
            x += n;
        }
        else if (di == "SE")
        {
            n = n / sqrt(2);
            x += n;
            y -= n;
        }
        else if (di == "S")
        {
            y -= n;
        }
        else if (di == "SW")
        {
            n = n / sqrt(2);
            x -= n;
            y -= n;
        }
        else if (di == "W")
        {
            x -= n;
        }
        else if (di == "NW")
        {
            n = n / sqrt(2);
            x -= n;
            y += n;
        }
    }

    double dist = sqrt((x * x) + (y * y));

    printf("%.3lf %.3lf\n", x, y);
    printf("%.3lf", dist);

    return 0;
}