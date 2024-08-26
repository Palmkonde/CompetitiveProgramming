#include <bits/stdc++.h>
#define MAX(a, b) (a > b) ? a : b
using namespace std;

const int N = 2e6 + 5;

int64_t arr[N];
int n;

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &arr[i]);
    }

    int64_t sn, bn;

    sn = bn = INT64_MIN;

    for (int i = 0; i < n; i++)
    {
        sn = MAX(sn + arr[i], arr[i]);
        bn = MAX(sn, bn);
    }

    printf("%lld", bn);

    return 0;
}