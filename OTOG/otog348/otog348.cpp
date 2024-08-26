#include <bits/stdc++.h>
#define MAX(x, y) (x > y) ? x : y
using namespace std;
using ull = unsigned long long;

const int N = 30005;

ull seg[4 * N], num[N];
ull bb;
ull n, m, aa;
char c;

void update(int node, int l, int r, int idx, ull val)
{
    if (l == r)
    {
        seg[node] = val;
        num[idx] = val;
        return;
    }

    int mid = l + (r - l) / 2;

    if (l <= idx and idx <= mid)
    {
        update(2 * node + 1, l, mid, idx, val);
    }
    else
    {
        update(2 * node + 2, mid + 1, r, idx, val);
    }

    seg[node] = MAX(seg[2 * node + 1], seg[2 * node + 2]);
}

ull query(int idx, int l, int r, int a, int b)
{
    if (a <= l and r <= b)
    {
        return seg[idx];
    }

    if (r < a or b < l)
    {
        return 0;
    }

    int mid = l + (r - l) / 2;
    ull ll = query(2 * idx + 1, l, mid, a, b);
    ull rr = query(2 * idx + 2, mid + 1, r, a, b);

    return MAX(ll, rr);
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> n >> m;

    while (m--)
    {
        cin >> c;
        if (c == 'B')
        {
            cin >> aa >> bb;
            update(0, 0, n - 1, aa - 1, bb);
        }

        else if (c == 'C')
        {
            cin >> aa;
            cout << query(0, 0, n - 1, 0, aa - 1) << "\n";
        }
    }

    return 0;
}