#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

pair<double, int> rate[N];
int k, p, q, m, b;

int main()
{
    scanf("%d", &k);

    for (int i = 0; i < k; i++)
    {
        scanf("%d%d", &p, &q);
        rate[i] = {(double)p / (double)q, q};
    }

    sort(rate, rate + k);

    scanf("%d", &m);

    int i = 0;
    while (m--)
    {
        scanf("%d", &b);

        double ans = 0.0;

        // printf("%lf %d\n", rate[i].first, rate[i].second);

        while (b > 0)
        {
            if (b >= rate[i].second)
            {
                ans += rate[i].first * rate[i].second;
                b -= rate[i].second;
                rate[i].second = 0;
                i++;
            }

            else if (b < rate[i].second)
            {
                ans += rate[i].first * (b);
                rate[i].second -= b;
                b = 0;
            }
        }

        printf("%.3lf\n", ans);
    }

    return 0;
}