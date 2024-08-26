#include <bits/stdc++.h>
using namespace std;

string code;

int main()
{
    cin >> code;

    int idx = 0;
    int fg = 0;

    int ans = 1;
    int cnt = 0;
    for (int i = 0; i < code.size(); i++)
    {
        if (code[i] == 'a')
        {
            idx = i;
            fg = 1;
        }

        if (i > idx and fg)
        {
            if (code[i] == ')')
            {
                if (cnt == 0)
                    continue;

                ans *= cnt;
                cnt = 0;
            }
            else if (code[i] == 'i')
            {
                if (cnt == 0)
                {
                    cnt += 2;
                }
                else
                {
                    cnt++;
                }
            }
        }
    }

    if (cnt)
        ans *= cnt;

    cout << ans;
    return 0;
}