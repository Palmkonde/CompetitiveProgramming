#include <bits/stdc++.h>
#define start first
#define end second
using namespace std;
using pii = pair<int, int>;

const int N = 1'000'005;

int x, y, z;
int line[N];
pii note[N];

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> x >> y >> z;

    for (int i = 1; i <= y; i++)
    {
        int a, b;
        cin >> a >> b;
        note[i] = {a, b};
    }

    for (int i = 0; i < z; i++)
    {
        int a;
        cin >> a;

        line[note[a].start] += 1;
        line[note[a].end + 1] -= 1;
    }

    int temp = 0;
    int mx = INT_MIN;
    int idx = 1;
    for (int i = 1; i <= x + 1; i++)
    {
        temp += line[i];
        line[i] = temp;

        if (mx < line[i])
        {
            mx = line[i];
            idx = i;
        }
    }

    cout << idx << " " << mx;

    return 0;
}