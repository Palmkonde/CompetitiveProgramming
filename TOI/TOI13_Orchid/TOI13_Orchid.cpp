#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;

int m;
int h[N], L[N];

int main()
{
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> h[i];
    }

    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        int idx = upper_bound(L, L + ans + 1, h[i]) - L;
        ans = max(ans, idx);
        L[idx] = h[i];
    }

    printf("%d", m - ans);

    return 0;
}

/*
5
1
4
3
3
6
*/