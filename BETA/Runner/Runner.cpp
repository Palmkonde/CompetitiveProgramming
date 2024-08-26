#include <bits/stdc++.h>
using namespace std;
using TUPLE = tuple<int, int, int>;

const int N = 100005;
const int M = 10005;

vector<TUPLE> v;
int path[M], ans[N], id[N]; // จำนวนคนในลู่, ความเร็วของสูงสุดรอบ,คนที่ชนะ
int n, m, a, l, s, lap;

int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &a, &l, &s);
        v.push_back({l, a, s});
    }

    sort(v.begin(), v.end());

    for (auto e : v)
    {
        tie(l, a, s) = e;

        path[l]++; //จำนวนคนเพิ่ม

        if (ans[path[l]] < s)
        {
            ans[path[l]] = s;
            id[path[l]] = a;
        }
        // printf("->%d %d %d %d\n", a, path[l], ans[path[l]], id[path[l]]);

        lap = max(lap, path[l]);
    }

    for (int i = 1; i <= lap; i++)
    {
        printf("%d\n", id[i]);
    }

    return 0;
}