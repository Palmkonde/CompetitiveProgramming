#include <bits/stdc++.h>
using namespace std;

int n;
int p[] = {2, 3, 5, 7};
vector<char> ans;

int main()
{
    scanf("%d", &n);

    if (n == 0 or n == 1)
    {
        printf("%d", n);
        return 0;
    }

    while (n != 1)
    {
        int fg = 0;
        for (int i = 0; i < 4; i++)
        {

            if (n % p[i] == 0 and !fg)
            {
                fg = 1;
                n /= p[i];
                ans.push_back(p[i] + '0');
            }
        }

        if (!fg)
        {
            printf("-1");
            return 0;
        }
    }

    sort(ans.begin(), ans.end());

    for (auto e : ans)
    {
        printf("%c", e);
    }

    return 0;
}