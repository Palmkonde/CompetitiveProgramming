#include <bits/stdc++.h>
using namespace std;

int n, m;
int visited[1005];

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> n >> m;

    int cnt = 1;
    int done = 0;

label:
    for (int i = 1; i <= n; i++)
    {

        if (visited[i])
        {
            if (done != n)
                goto ndone;

            else
                continue;
        }

        if (cnt == m)
        {
            visited[i] = true;
            cout << i << " ";
            cnt = 0;
            done++;
        }

        // cout << i << " " << cnt << "\n";
        cnt++;

    ndone:

        if (i >= n)
        {
            goto label;
        }
    }

    return 0;
}