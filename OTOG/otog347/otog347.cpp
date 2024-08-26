/*
#include <bits/stdc++.h>
using namespace std;

const int N = 30005;

int64_t p[N];
int64_t n, m, a, b;
char c;

int main()
{
    scanf("%d %d", &n, &m);

    while (m--)
    {
        scanf(" %c", &c);

        if (c == 'B')
        {
            scanf("%lld %lld", &a, &b);

            p[a] = b;
        }

        else if (c == 'C')
        {
            scanf("%d", &a);

            int64_t mx = INT_MIN;
            for (int64_t i = 1; i <= a; i++)
            {
                if (mx < p[i])
                {
                    mx = p[i];
                }
            }

            printf("%lld\n", mx);
        }
    }

    return 0;
}
*/

#include <bits/stdc++.h>
#define MAX(x, y) (x > y) ? x : y
using namespace std;

const int N = 30005;

int64_t seg[4 * N], num[N];
int64_t bb;
int n, m, aa;
char c;

void update(int node, int l, int r, int idx, int64_t val)
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

int64_t query(int idx, int l, int r, int a, int b)
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
    int64_t ll = query(2 * idx + 1, l, mid, a, b);
    int64_t rr = query(2 * idx + 2, mid + 1, r, a, b);

    return MAX(ll, rr);
}

int main()
{
    scanf("%d %d", &n, &m);

    while (m--)
    {
        scanf(" %c", &c);

        if (c == 'B')
        {
            scanf("%d %lld", &aa, &bb);
            update(0, 0, n - 1, aa - 1, bb);
        }

        else if (c == 'C')
        {
            scanf("%d", &aa);
            printf("%lld\n", query(0, 0, n - 1, 0, aa - 1));
        }
    }

    return 0;
}