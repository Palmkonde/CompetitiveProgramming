#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int n, a, d;
vector<pii> v;

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &a, &d);
        v.push_back({a, d});
    }

    sort(v.begin(), v.end());

    int64_t t = 0, ans = 0;
    for (auto e : v)
    {
        t += e.first;
        ans += e.second - t;
    }

    printf("%lld", ans);

    return 0;
}