#include <bits/stdc++.h>
using namespace std;

const int N = 500005;
const int S = 1e6 + 5;

int n, x;
bool s[S];
int a[N];

int main()
{
    scanf("%d", &n);

    scanf("%d", &x);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    s[1] = true;
    for (int i = 2; i < S / 2; i++)
    {
        if (s[i])
            continue;
        for (int j = 2 * i; j < S; j += i)
        {
            s[j] = true;
        }
    }

    vector<int> idx;
    for (int i = 0; i < n; i++)
    {
        if (!s[a[i]])
            idx.push_back(i);
    }

    int l = 0, r = x - 1;
    int mn = INT_MAX;
    while (l < idx.size() and r < idx.size())
    {
        mn = min(mn, idx[r] - idx[l] + 1);
        l++;
        r++;
    }

    printf("%d", mn);

    return 0;
}