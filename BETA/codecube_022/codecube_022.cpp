#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

bool cnted[1005][1005];
int n;

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> n;

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        if (!cnted[x][y])
            ans++;
        cnted[x][y] = true;
    }

    cout << ans;

    return 0;
}