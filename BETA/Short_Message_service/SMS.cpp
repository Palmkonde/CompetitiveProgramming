#include <bits/stdc++.h>
using namespace std;

int score[10];
string s;
int cnt = 7;
int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    while (1)
    {
        cin >> s;
        if (s == "!")
        {
            break;
        }

        for (int i = 0; i < s.size(); i++)
        {
            int idx = s[i] - 'A';
            if (score[idx] != -1)
                score[idx]++;
        }

        if (cnt == 1)
            continue;

        int mnf = INT_MAX, mns = INT_MAX, imnf = -1;
        for (int i = 0; i < 7; i++)
        {
            if (score[i] != -1)
            {
                if (score[i] < mnf)
                {
                    mnf = score[i];
                    imnf = i;
                }
            }
        }

        for (int i = 0; i < 7; i++)
        {
            if (score[i] != -1)
            {
                if (score[i] < mns and i != imnf)
                {
                    mns = score[i];
                }
            }
        }

        if (mns == mnf)
        {
            continue;
        }
        else
        {
            if (imnf == -1)
                continue;

            score[imnf] = -1;
            cnt--;
        }
    }

    vector<pair<int, char>> v;
    for (int i = 0; i < 7; i++)
    {
        if (score[i] == -1)
            continue;
        v.push_back({score[i], (char)(i + 'A')});
    }

    sort(v.begin(), v.end(), [](const pair<int, char> &a, const pair<int, char> &b)
         { return (a.first == b.first) ? a.second < b.second : a.first > b.first; });
    cout << v.size() << "\n";
    for (auto e : v)
    {
        cout << e.second << " " << e.first << "\n";
    }

    return 0;
}