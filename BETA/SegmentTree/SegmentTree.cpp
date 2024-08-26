#include <bits/stdc++.h>
using namespace std;

const int N = 500000;

int arr[N];
int n, q;
int seg[4 * N];

void build(int idx, int l, int r)
{
    if (l == r)
    {
        seg[idx] == arr[l];

        return;
    }

    int mid = l + (r - l) / 2;
    build(2 * idx + 1, l, mid);
    build(2 * idx + 2, mid + 1, r);

    seg[idx] = max(seg[2 * idx + 1], seg[2 * idx + 2]);
}

int query(int idx, int l, int r, int &a, int &b)
{
    if (a <= l and b >= r)
    {
        return seg[idx];
    }

    if (r < a or l > b)
    {
        return INT_MIN;
    }

    int mid = l + (r - l) / 2;
    int ll = query(2 * idx + 1, l, mid, a, b);
    int rr = query(2 * idx + 2, mid + 1, r, a, b);

    return max(ll, rr);
}

void update(int node, int l, int r, int &idx, int &val)
{
    if (l == r)
    {
        arr[idx] = val;
        seg[node] = val;
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

    seg[node] = max(seg[2 * node + 1], seg[2 * node + 2]);
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> n >> q;

    build(0, 0, n - 1);

    while (q--)
    {
        char com;
        int i, j;

        cin >> com >> i >> j;

        if (com == 'P')
        {
            i--;
            j--;
            cout << query(0, 0, n - 1, i, j) << "\n";
        }
        else if (com == 'U')
        {
            i--;
            update(0, 0, n - 1, i, j);
        }
    }

    return 0;
}