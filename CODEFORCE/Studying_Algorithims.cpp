#include <bits/stdc++.h>
using namespace std;

int n, x;
int arr[105];

int main()
{
    scanf("%d %d", &n, &x);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    sort(arr, arr + n);

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (x >= arr[i])
        {
            x -= arr[i];
            cnt++;
        }

        else
            break;
    }

    printf("%d", cnt);

    return 0;
}