#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int64_t num[N];
int64_t n, sum;

int main()
{

    scanf("%lld", &n);

    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &num[i]);
        sum += num[i];
    }

    int cnt = 0;
    for (int i = 2; i <= n - 1; i++)
    {
        int64_t mean = (num[i - 1] + num[i] + num[i + 1]);

        mean /= 3;

        if (mean > num[i])
        {
            cnt++;
            sum -= num[i];
            sum += mean;
        }
    }

    printf("%lld %lld", cnt, sum);

    return 0;
}