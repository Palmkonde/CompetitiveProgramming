#include <bits/stdc++.h>
using namespace std;
using TUPLE = tuple<int, int, int>;

int n, t;
int s, w, h, o;
vector<TUPLE> v;

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> n >> t;

    for (int i = 0; i < n; i++)
    {
        cin >> s >> h >> w >> o;

        v.push_back({s, h, o});
        v.push_back({s + w + 1, h + 1, -o});
    }

    sort(v.begin(), v.end());

    return 0;
}