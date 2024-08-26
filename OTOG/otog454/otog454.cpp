#include <bits/stdc++.h>
using namespace std;

int a, x, b, y;

int main()
{
    scanf("%d%d%d%d", &a, &x, &b, &y);

    int s = x + y;
    int ans1 = 0, ans2 = 0;
    if (s > b)
    {
        ans1 = s - b;
        ans2 = b;
    }

    else
    {
        ans1 = 0;
        ans2 = s;
    }

    printf("%d %d", ans1, ans2);

    return 0;
}