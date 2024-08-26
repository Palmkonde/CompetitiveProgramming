#include <bits/stdc++.h>
using namespace std;

int t, n;
string a, b, p = "", c = "", temp;
int main()
{
    scanf("%d", &t);

    while (t--)
    {
        p = c = "";

        cin >> a >> b;
        p = a + b;

        scanf("%d", &n);
        while (n--)
        {
            cin >> temp;
            c += temp;
        }

        int pnt[26] = {0};
        int cnt[26] = {0};

        for (int i = 0; i < p.length(); i++)
        {
            pnt[p[i] - 'a']++;
        }

        for (int i = 0; i < c.length(); i++)
        {
            cnt[c[i] - 'a']++;
        }

        bool yep = false;
        for (int i = 0; i < 26; i++)
        {
            // printf("%d %d\n", cnt[i], pnt[i]);
            if (cnt[i] > pnt[i])
            {
                yep = true;
            }
        }

        if (yep)
            printf("NO\n");
        else
            printf("YES\n");
    }

    return 0;
}