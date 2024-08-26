#include <bits/stdc++.h>
using namespace std;

const int N = 5 * 1e6 + 5;

int n, k;
int h[N];
vector<int> ans;

int main()
{
    scanf("%d%d", &n, &k);

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &h[i]);
    }

    for (int i = 1; i <= n; i++)
    {
        if (h[i] > h[i - 1] and h[i] > h[i + 1])
            ans.push_back(h[i]);
    }

    if (ans.empty())
    {
        printf("-1");
        return 0;
    }

    sort(ans.begin(), ans.end());
    ans.resize(unique(ans.begin(), ans.end()) - ans.begin());

    if (ans.size() >= k) // แสดงว่าต้องเลือกป้อมที่สูงก่อน
        reverse(ans.begin(), ans.end());

    for (int i = 0; i < min(k, int(ans.size())); i++)
    {
        printf("%d\n", ans[i]);
    }

    return 0;
}