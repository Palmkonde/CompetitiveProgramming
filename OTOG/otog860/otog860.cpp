#include <bits/stdc++.h>
using namespace std;
using pic = pair<int, char>;

const int N = 155;
const int MOD = 1e9 + 7;

int n, m, x, l;
int dp[N][2505];
string wnt;
vector<pic> adj[N];

int recur(int now, int len)
{
    if (len > l)
        return 0;
    if (dp[now][len] != 0)
        return dp[now][len];
    if (len == l)
        return 1;

    int res = 0;
    for (auto e : adj[now])
    {
        int nx = e.first;
        char nw = e.second;

        if (wnt[len] == nw)
        {
            res += recur(nx, len + 1);
            res %= MOD;
        }
    }

    return dp[now][len] = res;
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> n >> m;

    int a, b;
    char c;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    cin >> x >> l;
    cin >> wnt;
    cout << recur(x, 0);

    return 0;
}