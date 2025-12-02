#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using tii = tuple<int, int, int>;

const int N = 2505;
const ll INF = 1e9 * 5000 + 5;

int n, m;
ll d[N];
vector<tii> edges;

int main() {
    cin >> n >> m;
    
    int u, v, w;
    for(int i=0; i<m; i++) {
        cin >> u >> v >> w;        
        edges.push_back({u, v, -w});
    }
    
    fill(d, d+N, INF);
    d[1] = 0;

    for(int i=1; i <= n-1; i++) {
        for(auto edge: edges) {
            tie(u, v, w) = edge;

            if(d[u] == INF) continue;
            d[v] = min(d[v], d[u] + w);
        }
    }

    // for(int i=1; i<=n; i++) {
    //     cout << d[i] << " ";
    // }
    // cout << "\n";
    
    for(int i=1; i <= n; i++) {
        for(auto edge: edges) {
            tie(u, v, w) = edge;

            if(d[u] == INF) continue;
            if(d[v] > d[u] + w) {
                d[v] = -INF;
            }
        }
    }
    
    // for(int i=1; i<=n; i++) {
    //     cout << d[i] << " ";
    // }
    
    if(d[n] == -INF) {
        cout << -1;
        return 0;
    }

    cout << d[n] * -1; 
    return 0;
}

/*
4 5
1 2 3
2 4 -1
1 3 -2
3 4 7
1 4 4
*/