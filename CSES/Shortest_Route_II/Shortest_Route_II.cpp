#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 505;
const ll INF = 1e9 * N;

int n, m, q;
ll d[N][N];

int main() {
    cin >> n >> m >> q;
    
    for(int i=1; i<=n; i++) {
        fill(d[i], d[i] + N, INF);
        for(int j=1; j<=n; j++) {
            if (i == j) d[i][j] = 0;
        }
    }

    ll u, v, w;
    for(int i=0; i<m; i++) {
        cin >> u >> v >> w;
        d[u][v] = min(d[u][v], w);
        d[v][u] = min(d[v][u], w);
    }
    

    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    
    while(q--) {
        cin >> u >> v;
        
        if(d[u][v] == INF) {
            cout << "-1\n";
            continue;
        }
        cout << d[u][v] << "\n";
    }
    return 0;
}