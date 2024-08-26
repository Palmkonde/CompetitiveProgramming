#include <bits/stdc++.h>
using namespace std;

const int N = 1e7;

int n;
bool arr[N];
int ans[N];

int main()
{
    // cin.tie(NULL)->sync_with_stdio(false);

    cin >> n;

    int idx = 1;
    for (int i = 2; i < N; i++)
    {
        if (not arr[i])
        {
            ans[idx++] = i;

            for (int j = 2; j * i < N; j++)
            {
                arr[j * i] = true;
            }
        }
    }

    cout << ans[n];

    return 0;
}