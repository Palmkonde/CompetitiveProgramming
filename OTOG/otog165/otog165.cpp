#include <bits/stdc++.h>
using namespace std;

string s;
int cnt, sum, last, cap, t1, t2;

int main()
{
    cin.tie()->sync_with_stdio(false);

    cin >> s;

    // last = 1:upper, 0:lower
    for (int i = 0; i < s.length(); i++)
    {
        int temp = isupper(s[i]);

        if (temp == last and temp != cap)
            cnt++;

        if (cnt == 1)
        {
            cap = !cap;
            cnt = 0;
        }
        else if (temp != cap)
        {
            sum++;
        }

        // printf("%c temp=%d last=%d cnt=%d sum=%d cap=%d\n", s[i], temp, last, cnt, sum, cap);

        last = temp;
    }

    printf("%d", sum);

    return 0;
}