#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int N = 1e5 + 5;

struct Node
{
    int mx, mn;
};

int n, a, b;
int arr[N];
char cmd;
Node Tree[4 * N];

void build(int idx, int l, int r)
{
    if (l == r)
    {
        Tree[idx].mx = Tree[idx].mn = arr[l];
        return;
    }

    int mid = l + (r - l) / 2;
    build(2 * idx + 1, l, mid);
    build(2 * idx + 2, mid + 1, r);

    Tree[idx].mx = max(Tree[2 * idx + 1].mx, Tree[2 * idx + 2].mx);
    Tree[idx].mn = min(Tree[2 * idx + 1].mn, Tree[2 * idx + 2].mn);

    return;
}

pii query(int idx, int l, int r, int &i, int &j)
{
    if (i <= l and r <= j)
    {
        return make_pair(Tree[idx].mx, Tree[idx].mn);
    }

    if (r < i or j < l)
    {
        return {INT_MIN, INT_MAX};
    }

    int mid = l + (r - l) / 2;

    pii ll = query(2 * idx + 1, l, mid, i, j);
    pii rr = query(2 * idx + 2, mid + 1, r, i, j);

    return make_pair(max(ll.first, rr.first), min(ll.second, rr.second));
}

void update(int idx, int l, int r, int &w, int &val)
{
    if (l == r)
    {
        Tree[idx].mx = val;
        Tree[idx].mn = val;
        arr[w] = val;

        return;
    }

    int mid = l + (r - l) / 2;

    if (l <= w and w <= mid)
    {
        update(2 * idx + 1, l, mid, w, val);
    }
    else
        update(2 * idx + 2, mid + 1, r, w, val);

    Tree[idx].mx = max(Tree[2 * idx + 1].mx, Tree[2 * idx + 2].mx);
    Tree[idx].mn = min(Tree[2 * idx + 1].mn, Tree[2 * idx + 2].mn);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    build(0, 0, n - 1);

    while (cin >> cmd >> a >> b)
    {
        if (cmd == 'U')
        {
            update(0, 0, n - 1, a, b);
        }

        if (cmd == 'Q')
        {
            pii ans = query(0, 0, n - 1, a, b);
            printf("%d %d\n", ans.second, ans.first);
        }
    }

    return 0;
}