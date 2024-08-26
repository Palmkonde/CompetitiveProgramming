#include <bits/stdc++.h>
using namespace std;
using pii = pair<char, int>;

const int N = 30;

struct pqData
{
    int w;
    char node;
    char cow;

    bool operator<(const pqData &other) const
    {
        return this->w > other.w;
    }
};

int p, w;
char a, b;

bool pp[N];
bool visited[N][N];
map<char, vector<pii>> mp;
map<char, pii> dist;
priority_queue<pqData> pq;

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> p;

    for (int i = 0; i < p; i++)
    {
        cin >> a >> b >> w;

        mp[a].push_back({b, w});
        mp[b].push_back({a, w});

        dist[a].second = INT_MAX;
        dist[b].second = INT_MAX;
    }

    for (auto e : mp)
    {
        if (isupper(e.first) and not pp[e.first - 'A'] and e.first != 'Z')
        {
            pq.push({0, e.first, e.first});
            dist[e.first].first = e.first;
            dist[e.first].second = 0;
            pp[e.first - 'A'] = true;
        }
    }

    while (!pq.empty())
    {
        pqData now = pq.top();
        pq.pop();

        if (visited[now.cow - 'A'][now.node - ((isupper(now.node) ? 'A' : 'a'))])
            continue;
        visited[now.cow - 'A'][now.node - ((isupper(now.node) ? 'A' : 'a'))] = true;

        for (auto e : mp[now.node])
        {
            char nx = e.first;
            int w = e.second;

            if (dist[nx].second > dist[now.node].second + w)
            {
                dist[nx].second = dist[now.node].second + w;
                dist[nx].first = now.cow;
                pq.push({dist[nx].second, nx, now.cow});
            }
        }
    }

    cout << dist['Z'].first << " " << dist['Z'].second;

    return 0;
}