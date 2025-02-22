#include<bits/stdc++.h>
using namespace std;

const int NODE = 1e5 + 5;

int n, m, cycle_start, cycle_end;
int parent[NODE];
vector<int> adj[NODE];
bool visited[NODE];

bool dfs(int u, int p) {
    visited[u] = true;
    parent[u] = p;

    for(auto neighbor: adj[u]) {
        if(neighbor == p) continue;
        if(visited[neighbor]) {
            cycle_end = u;
            cycle_start = neighbor;
            return true;
        }

        if(dfs(neighbor, u)) {
            return true;
        }
    }
    
    return false;
}

int main() {
    cin >> n >> m;
    
    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v; 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    bool possible = false;
    for(int i=1; i<=n; i++) {
        if(visited[i] == false && !possible) {
            if(dfs(i, -1)) {
                possible = true;
            }
        }
    }
    
    if(!possible) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    
    // print path
    vector<int> answer({cycle_start});
    for(int node=cycle_end; node!=parent[cycle_start]; node=parent[node]) {
        answer.push_back(node);
    }
    
    cout << answer.size() << "\n";

    for(auto element: answer) {
        cout << element << " ";
    }

    return 0;
}