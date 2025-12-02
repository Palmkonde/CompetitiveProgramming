#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2505;
const int M = 5005;
const ll INF = 1e9 * M;

ll d[N];
int n, m, x;
int parent[N];
vector<tuple<int, int, int>> edges;
vector<int> adj[N];

int main() {
    cin >> n >> m;

    int u, v, w;
    for(int i=0; i<m; i++) {
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    
    // from differet perspective we don't know that what source we should selected
    // We can assume that every node can reach to with 0 cost
    fill(d, d+N, 0); 
    fill(parent, parent+N, -1);

    x = -1;

    for(int i=1; i<=n; i++) {
        x = -1;
        for(auto edge: edges) {
            tie(u, v, w) = edge;
            if(d[u] == INF) continue;
            
            if(d[v] > d[u] + w) {
                d[v] = d[u] + w;
                parent[v] = u;
                x = v;
            }
        }
        
        if(x == -1) break;
    }
    
    if(x == -1) {
        cout << "NO";
        return 0;
    }
    
    cout << "YES\n";
    
    for(int i=0; i<n; i++) { // Check da loop that definitely in n steps
        x = parent[x];
    }

    vector<int> cycle;
    for(int y=x;; y=parent[y]) {
        cycle.push_back(y);
        if(y == x && cycle.size() > 1) break;
    }
    
    reverse(cycle.begin(), cycle.end());
    for(auto e: cycle) cout << e << " ";
}