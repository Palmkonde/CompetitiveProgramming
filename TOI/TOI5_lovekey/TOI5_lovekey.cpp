#include <bits/stdc++.h>
using namespace std;

int n;
string t;
map<string, string> s1 = {{"00", "0"}, {"11", "1"}}, s2 = {{"01", "1"}, {"10", "0"}}, s3 = {{"00", "1"}, {"11", "0"}}, s4 = {{"10", "1"}, {"01", "0"}};
vector<string> ans;
int st = 1;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        cin >> t;

        string tmp = "";
        for (int i = 0; i < t.size(); i += 2)
        {
            string sub = t.substr(i, 2);

            if (st == 1)
            {
                if (sub == "11")
                {
                    st = 2;
                }

                tmp += s1[sub];
            }
            else if (st == 2)
            {
                if (sub == "10")
                    st = 3;
                if (sub == "01")
                    st = 4;

                tmp += s2[sub];
            }

            else if (st == 3)
            {
                if (sub == "00")
                    st = 2;
                if (sub == "11")
                    st = 1;

                tmp += s3[sub];
            }

            else if (st == 4)
            {
                if (sub == "01")
                    st = 3;

                tmp += s4[sub];
            }
        }

        if (tmp.size() != 8)
            continue;

        ans.push_back(tmp);
    }

    for (auto e : ans)
    {
        int a = 0;
        for (int i = 0, j = 7; i < e.size() and j >= 0; i++, j--)
        {
            if (e[i] == '1')
            {
                a |= (1 << j);
            }
        }

        printf("%c", a);
    }

    return 0;
}