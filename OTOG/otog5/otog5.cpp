#include <bits/stdc++.h>
using namespace std;

int n, m, plate, power;

int main()
{
    int p[20] = {1,
                 3,
                 9,
                 27,
                 81,
                 243,
                 729,
                 2187,
                 6561,
                 19683,
                 59049,
                 177147,
                 531441,
                 1594323,
                 4782969,
                 14348907,
                 43046721,
                 129140163,
                 387420489,
                 1162261467};

    scanf("%d", &n);

    m = n;
    while (n)
    {
        int r = n % 3;
        n /= 3;

        if (r == 2)
        {
            m += p[power];
            n += 1;
        }
        power++;

        if (r)
            plate++;
    }

    printf("%d %d", plate, m);

    return 0;
}