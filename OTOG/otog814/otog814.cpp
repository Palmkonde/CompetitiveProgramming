#include <bits/stdc++.h>
using namespace std;

int n, q, x;

struct myHash
{
    size_t operator()(const vector<pair<int, int>> &v) const
    {
        size_t h;
        for (auto e : v)
        {
            h ^= ((hash<int>{}(e.first)) ^ (hash<int>{}(e.second))) + 0x9e3779b9 + (h << 6) + (h >> 2);
        }
        return h;
    }
};

vector<pair<int, int>> edge;
unordered_map<vector<pair<int, int>>, int, myHash> mp;
int main()
{
    scanf("%d %d", &n, &q);

    while (n--)
    {
        scanf("%d", &x);
        for (int i = 0; i < x - 1; i++)
        {
            int u, v;
            scanf("%d %d", &u, &v);

            if (v < u)
                swap(u, v);

            edge.push_back({u, v});
        }
        sort(edge.begin(), edge.end());
        mp[edge]++;
        edge.clear();
    }

    while (q--)
    {
        scanf("%d", &x);

        for (int i = 0; i < x - 1; i++)
        {
            int u, v;
            scanf("%d %d", &u, &v);

            if (v < u)
                swap(u, v);
            edge.push_back({u, v});
        }
        sort(edge.begin(), edge.end());
        printf("%d\n", mp[edge]);
        edge.clear();
    }

    return 0;
}

/*

*/