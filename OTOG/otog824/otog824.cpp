#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n;
int arr[N], p[N], b[N];
vector<int> L;

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        p[i] = lower_bound(b + 1, b + ans + 1, arr[i]) - b;
        ans = max(ans, p[i]);
        b[p[i]] = arr[i];
    }

    cout << ans << "\n";

    vector<int> T;

    int require = ans;

    for (int i = n; i >= 1; --i)
    {
        if (p[i] == require)
        {
            T.push_back(i);
            require--;
        }
    }

    int i = T.size();
    while (i--)
    {
        cout << T[i] << " ";
    }
    return 0;
}

/*
https://codeforces.com/blog/entry/12274
*/