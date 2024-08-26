#include <bits/stdc++.h>
using namespace std;

int n;
int x;
int arr[100005];
deque<int> dq;

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = 0;

    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        dq.push_back(arr[i]);
    }

    int cnt = 0;
    while (not dq.empty())
    {
        ans += dq.front();
        dq.pop_front();
        cnt++;

        if (dq.empty())
        {
            break;
        }

        if (cnt == 2)
        {
            ans += dq.back();
            dq.pop_back();
            cnt++;
        }

        if (cnt == 3)
        {
            dq.pop_back();
            cnt = 0;
        }
    }

    cout << ans;

    return 0;
}