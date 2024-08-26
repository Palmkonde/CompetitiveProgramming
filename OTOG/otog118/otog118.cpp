#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int N = 1002;

struct work
{
    int me;
    int f;
};

int n, a, b;
work w[N];
int sum = 0;

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        sum += y;
        w[i] = {x, y};
    }

    return 0;
}

/*
4 0 1
1 99
1 98
1 97
1 96
*/