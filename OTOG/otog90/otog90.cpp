#include <bits/stdc++.h>
using namespace std;

int n, b;
int num[500002];

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> n >> b;

    int l = 1, r = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
        r = max(r, num[i]);
    }

    while (l < r)
    {
        int mid = l + (r - l) / 2;

        int tmp = 0;

        for (int i = 0; i < n; i++)
        {
            tmp += ceil((num[i] * 1.0) / (mid * 1.0));
        }

        // printf("->%d %d %d %d\n", l, mid, r, tmp);

        if (tmp > b)
        {
            l = mid + 1;
        }
        else
            r = mid;
    }

    cout << r;

    return 0;
}