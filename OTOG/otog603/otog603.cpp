#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int64_t l, r, mx, freq;
};

const int N = 200005;
Node seg[4 * N];
int lazy[4 * N];
int n, m;

void build(int idx, int l, int r)
{
    if (l == r)
    {
        seg[idx] = {l, r, 0, 1};
        return;
    }

    int ll = 2 * idx + 1, rr = 2 * idx + 2;
    int mid = l + (r - l) / 2;

    build(ll, l, mid);
    build(rr, mid + 1, r);

    if (seg[ll].mx == seg[rr].mx)
    {
        seg[idx].mx = seg[ll].mx;
        seg[idx].freq = seg[ll].freq + seg[rr].freq - (seg[ll].r + 1 == seg[rr].l); //อยู่ติดกันรึป่าว?
        seg[idx].l = seg[ll].l;
        seg[idx].r = seg[rr].r;
    }
    else
        seg[idx] = (seg[ll].mx > seg[rr].mx) ? seg[ll] : seg[rr];
}

void push(int idx, int l, int r)
{
    seg[idx].mx += lazy[idx];
    if (l != r)
    {
        lazy[2 * idx + 1] += lazy[idx];
        lazy[2 * idx + 2] += lazy[idx];
    }
    lazy[idx] = 0;
}

void update(int idx, int l, int r, int a, int b, int val)
{
    push(idx, l, r);
    if (r < a or b < l)
    {
        return;
    }

    int ll = 2 * idx + 1;
    int rr = 2 * idx + 2;

    if (a <= l and r <= b)
    {
        lazy[idx] += val;
        push(idx, l, r);
        return;
    }

    int mid = l + (r - l) / 2;
    update(ll, l, mid, a, b, val);
    update(rr, mid + 1, r, a, b, val);

    if (seg[ll].mx == seg[rr].mx)
    {
        seg[idx].mx = seg[ll].mx;
        seg[idx].freq = seg[ll].freq + seg[rr].freq - (seg[ll].r + 1 == seg[rr].l); //อยู่ติดกันรึป่าว?
        seg[idx].l = seg[ll].l;
        seg[idx].r = seg[rr].r;
    }
    else
        seg[idx] = (seg[ll].mx > seg[rr].mx) ? seg[ll] : seg[rr];
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> n >> m;

    int a, b, c;

    build(0, 0, n - 1);

    while (m--)
    {
        cin >> a >> b >> c;
        a--;
        b--;
        update(0, 0, n - 1, a, b, c);

        cout << seg[0].mx << " " << seg[0].freq << "\n";
    }

    return 0;
}