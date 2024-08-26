#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1000005;

ll n, sum;
bool used[N], mark[N];
vector<ll> num(10005);

int main()
{
    scanf("%lld", &n);

    ll v;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &v);
        sum += v;
        num[i] = v;
        mark[v] = true;
    }

    ll tmp, idx;
    for (size_t i = 1; i <= sum + 1; i++)
    {
        memset(used, 0, sizeof(used));

        if (mark[i])
            continue;
        tmp = i;
        // printf("%d\n", tmp);

        // condition
        while (tmp > 0)
        {
            int idx = upper_bound(num.begin() + 1, num.begin() + n + 1, tmp) - (num.begin());
            idx--;

            while (used[num[idx]] and idx >= 1)
            {
                idx--;
            }

            if (idx < 1)
            {
                printf("%lld", i);
                return 0;
            }

            // printf("%d->", num[idx]);
            tmp -= num[idx];
            used[num[idx]] = true;
        }

        // printf("\n");
    }

    // printf("%d", tmp);

    return 0;
}