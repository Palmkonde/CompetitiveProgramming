#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

struct node
{
    int sum, pref, suff, mxsum;
};

int n, m;
int room[N];
node seg[4 * N];

void build(int l, int r, int idx)
{
    if (l == r)
    {
        seg[idx].sum = room[l];
        seg[idx].pref = room[l];
        seg[idx].suff = room[l];
        seg[idx].mxsum = room[l];
        return;
    }

    int mid = l + (r - l) / 2;
    build(l, mid, 2 * idx + 1);
    build(mid + 1, r, 2 * idx + 2);

    int lidx = 2 * idx + 1;
    int ridx = 2 * idx + 2;

    seg[idx].sum = seg[lidx].sum + seg[ridx].sum;
    seg[idx].pref = max(seg[lidx].pref, seg[lidx].sum + seg[ridx].pref);
    seg[idx].suff = max(seg[ridx].suff, seg[ridx].sum + seg[lidx].suff);

    seg[idx].mxsum = max({seg[idx].pref,
                          seg[idx].suff,
                          seg[lidx].mxsum,
                          seg[ridx].mxsum,
                          seg[lidx].suff + seg[ridx].pref});
}

node query(int idx, int l, int r, int a, int b)
{
    node res;

    res.sum = res.pref = res.suff = res.mxsum = 0;

    if (a <= l and b >= r)
    {
        return seg[idx];
    }

    if (r < a or b < l)
    {
        return res;
    }

    int mid = l + (r - l) / 2;
    node ll = query(2 * idx + 1, l, mid, a, b);
    node rr = query(2 * idx + 2, mid + 1, r, a, b);

    res.sum = ll.sum + rr.sum;
    res.pref = max(ll.pref, ll.sum + rr.pref);
    res.suff = max(rr.suff, rr.sum + ll.suff);

    res.mxsum = max({res.pref,
                     res.suff,
                     ll.mxsum,
                     rr.mxsum,
                     ll.suff + rr.pref});

    return res;
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> room[i];
    }

    build(0, n - 1, 0);

    int a, b;
    while (m--)
    {
        cin >> a >> b;
        cout << (int)(query(0, 0, n - 1, a, b).mxsum) << "\n";
    }

    return 0;
}
/*
https://www.geeksforgeeks.org/maximum-subarray-sum-given-range/
https://www.geeksforgeeks.org/range-query-largest-sum-contiguous-subarray/
ดูสองอันนี้เข้าใจเลย
*/