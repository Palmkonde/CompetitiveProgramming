#include <bits/stdc++.h>
using namespace std;

int n, arr[29];

int main()
{
    arr[1] = 7;
    arr[2] = -2;
    arr[3] = -2;

    scanf("%d", &n);
    for (int i = 4; i <= n; i++)
    {
        arr[i] = (arr[i - 2] * 3) + (arr[i - 3] * 4);
    }

    printf("%d", arr[n]);

    return 0;
}