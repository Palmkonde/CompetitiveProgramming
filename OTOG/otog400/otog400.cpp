#include <bits/stdc++.h>
using namespace std;

int n, a, b;
int h, m;
int t;

int main()
{
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d %d", &a, &b);

        h = 20 - a;
        m = 45 - b;
        t = ((h * 60 + m) < 0 ? 0 : (h * 60 + m));

        printf("%d %d\n", t, (t + 1) / 2);
    }
}