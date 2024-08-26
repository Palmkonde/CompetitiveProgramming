#include <bits/stdc++.h>
using namespace std;

long long prefix[100002];
int arr[100002];
int n, q;

void makeprefix()
{
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        prefix[i] = arr[i] + prefix[i - 1];
    }
}
long long sumRange(int i, int j)
{
    if (i == 0)
        return prefix[j];
    else
    {
        return (long long)prefix[j] - prefix[i - 1];
    }
}

int main()
{
    int t, x;
    cin >> t;
    while (t--)
    {
        cin >> n >> q;
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        makeprefix();
        while (q--)
        {
            int i, j;
            cin >> i >> j;
            cout << sumRange(i, j) << endl;
        }
    }

    return 0;
}