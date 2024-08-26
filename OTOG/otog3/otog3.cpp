#include <bits/stdc++.h>
using namespace std;

int n;
string s;
int a[31];
int sm, mx;

int main()
{
    scanf("%d", &n);

    while (n--)
    {
        cin >> s;

        mx = 0;
        sm = 0;
        memset(a, 0, sizeof(a));
        for (int i = 0; i < s.size(); i++)
        {
            s[i] = tolower(s[i]);
            a[s[i] - 'a'] += 1;
            mx = max(s[i] - 'a', mx);
        }

        sort(a, a + mx + 1, greater<int>());

        for (int i = 0, st = 26; i <= mx; i++, st--)
        {
            if (a[i] == 0)
                break;

            sm += a[i] * (st);
        }
        printf("%d\n", sm);
    }

    return 0;
}