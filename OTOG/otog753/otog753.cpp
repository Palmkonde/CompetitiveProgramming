#include <bits/stdc++.h>
#define L     \
    {         \
        0, -1 \
    }
#define R    \
    {        \
        0, 1 \
    }
#define U     \
    {         \
        -1, 0 \
    }
#define D    \
    {        \
        1, 0 \
    }
#define UR    \
    {         \
        -1, 1 \
    }
#define UL     \
    {          \
        -1, -1 \
    }
#define DR   \
    {        \
        1, 1 \
    }
#define DL    \
    {         \
        1, -1 \
    }
using namespace std;

int64_t cnt[9];
int64_t n, m, k;
int di[8][2] = {U, D, R, L, UR, UL, DR, DL};
map<pair<int, int>, int64_t> mp; // pos, cnt
vector<pair<int, int>> bb;
set<pair<int, int>> bomb;

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> n >> m;
    cin >> k;

    int a, b, na, nb;
    for (int i = 0; i < k; i++)
    {
        cin >> a >> b;
        bomb.insert({a, b});
        bb.push_back({a, b});
    }

    for (auto e : bb)
    {
        a = e.first;
        b = e.second;

        // cout << a << " " << b << "\n";

        for (int i = 0; i < 8; i++)
        {
            na = a + di[i][0];
            nb = b + di[i][1];

            if (na < 1 or nb < 1 or na > n or nb > m)
                continue;
            if (bomb.find({na, nb}) != bomb.end())
                continue;

            mp[{na, nb}]++;

            /*
            cout << "na= " << na << " "
                 << "nb= " << nb << " " << mp[{na, nb}] << "\n";
            */
        }
    }

    int64_t sum = 0;
    for (auto e : mp)
    {
        cnt[e.second]++;
        // cout << e.first.first << " " << e.first.second << " " << e.second << "\n";
    }

    for (int i = 0; i < 9; i++)
    {
        sum += cnt[i];
    }

    int64_t zero = (n * m) - (sum + k);
    for (int i = 0; i < 9; i++)
    {
        if (i)
            cout << i << " " << cnt[i] << "\n";
        else
        {
            cout << 0 << " " << zero << "\n";
        }
    }

    return 0;
}