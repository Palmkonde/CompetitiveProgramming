#include <bits/stdc++.h>
using namespace std;

int n, x;

int counting(int a)
{
    int cnt = 0;
    for (int i = 1; i * i <= a; i++)
    {
        if (a % i == 0)
        {
            cnt += i * i == a ? 1 : 2;
        }
    }

    return cnt;
}

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);

        printf("%d\n", counting(x));
    }

    return 0;
}