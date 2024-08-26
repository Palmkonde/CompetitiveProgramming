#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A, B, C;
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> A >> B >> C;

    for (int a = 1; a <= 100; a++)
    {
        for (int c = 1; c <= 100; c++)
        {
            if (a * c == A)
            {
                for (int b = -1000; b <= 1000; b++)
                {
                    for (int d = -1000; d <= 1000; d++)
                    {
                        if (b * d == C)
                        {
                            if (a * d + b * c == B)
                            {
                                cout << a << " " << b << " " << c << " " << d;
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }

    cout << "No Solution";
    return 0;
}