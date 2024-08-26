#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;

int n, a, w, ans;
int arr[N];

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a);
        arr[a] += 1;
    }
    scanf("%d", &w);

    for (int i = 0; i < N; i++)
    {
        if (arr[i] == 0)
            continue;
        else
        {
            int ww = abs(w - arr[i]);

            if (arr[ww] != 0)
            {
                ans += arr[i];
            }
        }
    }

    printf("%d", ans);

    return 0;
}