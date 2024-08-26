#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int n, m, k, l;
int b;

vector<int> a;

int main()
{
    scanf("%d%d%d%d", &n, &m, &k, &l);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &b);
        a.push_back(b);
    }

    sort(a.begin(), a.end());

    while (k--)
    {
        int ans = 0;
        int cur = 0;
        for (int i = 0; i < m; i++)
        {
            scanf("%d", &b);

            int upper = upper_bound(a.begin() + cur, a.end(), b + l) - a.begin();
            int lower = lower_bound(a.begin() + cur, a.end(), b - l) - a.begin();

            cur = max(cur, upper);
            ans += upper - lower;
        }

        printf("%d\n", ans);
    }

    return 0;
}