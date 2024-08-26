#include <bits/stdc++.h>
using namespace std;

char mp[] = {'9', '1', '2', '3', '4', '5', '6', '7', '8'};
int w1, w2, w3;
string n, code, ans;

int main()
{
    cin.tie(NULL)->sync_with_stdio(0);

    cin >> n;
    w1 = n[0] - '0';
    w2 = n[1] - '0';
    w3 = n[2] - '0';

    cin >> code;

    int tmp, t, a, b, c;
    for (int i = 0; i < code.size(); i++)
    {
        tmp = code[i] - '0';
        tmp = (tmp - 1) % 9;

        a = (w1 + tmp) % 9;
        b = ((a - 1) + w2) % 9;
        c = ((b - 1) + w3) % 9;

        printf("%d %d %d\n", w1, w2, w3);

        w1 = mp[(2 * w1) % 9] - '0';
        w2 = mp[w2 - 1] - '0';
        w3 = mp[(2 * w3) % 9] - '0';

        ans.push_back(mp[c]);
    }

    for (auto e : ans)
    {
        cout << e;
    }

    return 0;
}