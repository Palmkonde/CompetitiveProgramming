#include <bits/stdc++.h>
using namespace std;

const int N = 5005;

int n;
int ss[N];
int dp1[N][N];
int dp2[N];

int recur(int l, int r)
{
    if (l == r)
        return ss[l];

    if (dp1[l][r] != -1)
        return dp1[l][r];

    int bf = abs(ss[r] - ss[l]);
    int res = max(recur(l + 1, r) + ss[l], recur(l, r - 1) + ss[r]) + bf;

    return dp1[l][r] = res;
}

int mcm(int l, int r)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            dp2[i] = max(dp2[i], dp2[j - 1] + dp1[j][i]);
        }
    }

    return dp2[r];
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> ss[i];
    }

    memset(dp1, -1, sizeof(dp1));
    recur(0, n - 1);
    cout << mcm(0, n - 1);

    return 0;
}