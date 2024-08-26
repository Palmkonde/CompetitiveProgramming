#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int n, q, a[N], l[N], r[N];
int b[N];

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> n >> q;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    int last = 0, answer = 0;
    for (int i = 1; i <= n; i++)
    {
        int it = lower_bound(b + 1, b + answer + 1, a[i]) - b;
        answer = max(answer, it);
        b[it] = a[i];
        l[i] = it;
    }

    reverse(a + 1, a + n + 1);

    memset(b, 0, sizeof(b));
    answer = 0;

    for (int i = 1, j = n; i <= n; i++, j--)
    {
        int it = lower_bound(b + 1, b + answer + 1, a[i]) - b;
        answer = max(answer, it);
        b[it] = a[i];
        r[j] = it;
    }

    int x;
    while (q--)
    {
        cin >> x;
        x++;
        cout << min(l[x], r[x]) - 1 << "\n";
    }

    return 0;
}