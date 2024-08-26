#include <bits/stdc++.h>
using namespace std;

const int N = 1'000'000;

int n;
int arr[N], L[N], p[N];

int main()
{
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        p[i] = lower_bound(L + 1, L + answer + 1, arr[i]) - L;
        answer = max(answer, p[i]);
        L[p[i]] = arr[i];
    }

    printf("%d\n", answer);

    int require = answer;
    vector<int> T;

    for (int i = n; i >= 1; i--)
    {
        if (require == p[i])
        {
            T.push_back(arr[i]);
            require--;
        }
    }

    reverse(T.begin(), T.end());

    for (auto e : T)
    {
        printf("%d ", e);
    }

    return 0;
}