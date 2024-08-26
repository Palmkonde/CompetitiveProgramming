#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;

int n;
int arr[N];

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int l = 0, r = n - 1;
    int mx = INT_MIN;
    while (l < r)
    {
        mx = max(mx, min(arr[l], arr[r]) * (r - l));
        if (arr[l] > arr[r])
        {
            r--;
        }

        else
            l++;
    }

    cout << mx;

    return 0;
}