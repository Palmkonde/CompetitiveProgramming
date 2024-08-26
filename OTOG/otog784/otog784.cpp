#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, h;
int arr[N], L[N];

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        int idx = upper_bound(L, L + answer + 1, arr[i]) - L;
        answer = max(answer, idx);
        L[idx] = arr[i];
    }

    printf("%d", n - answer);

    return 0;
}