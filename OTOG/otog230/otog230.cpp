#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int Cx, Cy, Cz, n, a, b;
int res = INT_MIN, x, y, z;

vector<pii> v;
int main()
{
    scanf("%d %d %d %d", &n, &Cx, &Cy, &Cz);

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &a, &b);
        v.push_back({a, 1});
        v.push_back({b + 1, -1});
    }

    sort(v.begin(), v.end(), [](const pii &aa, const pii &bb)
         {
        if(aa.first == bb.first)
        {
            return aa.second < bb.second;
        } 
        else return aa.first < bb.first; });

    x = n;
    for (auto e : v)
    {
        if (e.second == 1)
        {
            x -= 1;
            y += 1;
        }
        else if (e.second == -1)
        {
            y -= 1;
            z += 1;
        }

        res = max(res, Cx * x + Cy * y + Cz * z);
    }

    printf("%d", res);
    return 0;
}