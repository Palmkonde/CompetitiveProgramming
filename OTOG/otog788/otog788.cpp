#include <bits/stdc++.h>
#define MAGIC 0x93779b9
using namespace std;

int n, m, q, x, y;
string name;

// magic number 0x9e3779b9
struct Hashing
{
    size_t operator()(const vector<int> &a) const
    {
        size_t h = a.size();
        for (auto e : a)
        {
            h ^= e + MAGIC + (h << 6) + (h >> 2);
        }
        return h;
    }
};

unordered_map<vector<int>, string, Hashing> rtn;

int main()
{
    scanf("%d %d %d", &n, &m, &q);

    for (int i = 0; i < n; i++)
    {
        cin >> name >> x;

        int ig[20] = {0};
        vector<int> temp;

        for (int j = 0; j < x; j++)
        {
            scanf("%d", &y);

            ig[y]++;
        }

        for (int j = 1; j <= m; j++)
        {
            temp.push_back(ig[j]);
        }

        rtn[temp] = name;
    }

    while (q--)
    {
        cin >> name;
        scanf("%d", &x);

        int ig[20] = {0};
        vector<int> temp;

        for (int i = 0; i < x; i++)
        {
            scanf("%d", &y);

            ig[y]++;
        }

        for (int i = 1; i <= m; i++)
        {
            temp.push_back(ig[i]);
        }

        if (name == rtn[temp])
        {
            printf("P");
        }
        else if (rtn[temp] == "")
        {
            printf("X");
        }
        else if (name != rtn[temp])
        {
            printf("- %s", rtn[temp].c_str());
        }

        printf("\n");
    }

    return 0;
}

/*
4 3 1
OTOG 3 1 2 3
OKOM 2 1 1
OCOM 2 1 1
WAKANDA 6 1 3 2 3 3 1
WAKANDA 3 1 1 1

*/