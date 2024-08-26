#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, m, k;
int pi[N], wn[N];

int main()
{
    scanf("%d%d%d", &n, &m, &k);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &pi[i]);
    }

    for (int i = 0; i < m; i++)
    {
        scanf("%d", &wn[i]);
    }

    sort(pi, pi + n);
    sort(wn, wn + n);

    // 45 60 60 80
    // 30 60 75

    // for (int i = 0; i < n; i++)
    //     printf("%d ", pi[i]);

    // printf("\n");
    // for (int i = 0; i < n; i++)
    //     printf("%d ", wn[i]);

    int cnt = 0;
    for (int i = 0, j = 0; i < m && j < n;)
    {
        if (abs(pi[j] - wn[i]) <= k)
        {
            cnt++;
            j++;
            i++;
        }
        else if (pi[j] < wn[i])
        {
            j++;
        }

        else if (pi[j] > wn[i])
        {
            i++;
        }
    }

    printf("%d", cnt);

    return 0;
}