#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
const int M = 30;

int n;
string t;
vector<tuple<string, vector<int>>> S;

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> t;
        vector<int> al(26);

        for (int j = 0; j < t.length(); j++)
        {
            if ((islower(t[j])))
            {
                al[t[j] - 'a']++;
            }
        }
        S.push_back({t, al});
    }

    sort(S.begin(), S.end(), [](const tuple<string, vector<int>> &a, const tuple<string, vector<int>> &b)
         {
             string sa, sb;
             vector<int> va, vb;

            tie(sa,va) = a;
            tie(sb,vb) = b;

             if (va == vb)
             {
                return sa < sb;
             }
             else
             {
                return  va > vb;
             } });

    for (int i = 0; i < n; i++)
    {
        string temp;
        vector<int> tt;

        tie(temp, tt) = S[i];

        cout << temp << "\n";
    }

    return 0;
}