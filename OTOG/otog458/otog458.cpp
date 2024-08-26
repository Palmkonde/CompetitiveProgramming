#include <bits/stdc++.h>
using namespace std;

int n;
string s;
map<string, int> mp2, mp3;
priority_queue<string, vector<string>, greater<string>> pq;
int mx2, mx3;

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> n;

    while (n--)
    {
        cin >> s;

        if (s.size() == 1)
            continue;
        for (int i = 0; i < s.size() - 1; i++)
        {
            mp2[s.substr(i, 2)]++;
            mx2 = max(mx2, mp2[s.substr(i, 2)]);
        }

        for (int i = 0; i < s.size() - 2; i++)
        {
            mp3[s.substr(i, 3)]++;
            mx3 = max(mx3, mp3[s.substr(i, 3)]);
        }
    }

    for (auto e : mp2)
    {
        if (e.second == mx2)
        {
            pq.push(e.first);
        }
    }

    while (not pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }

    cout << "\n";

    for (auto e : mp3)
    {
        if (e.second == mx3)
        {
            pq.push(e.first);
        }
    }

    while (not pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}