#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, m;
int in_degree[N];
vector<int> adj[N];
queue<int> q;

int main() {
    cin >> n >> m;
    
    for(int i=0; i<m;i++) {
        int a, b;
        cin >> a >> b;
        
        adj[a].push_back(b);
        in_degree[b]++;
    }
   
    for(int i=1; i<=n; i++) {
        if(in_degree[i] == 0) {
            q.push(i);
        }
    }
    
    vector<int> answer;
    while(!q.empty()) {
        int node_now = q.front();
        answer.push_back(node_now);
        q.pop();

        for(auto neighbor: adj[node_now]) {
            in_degree[neighbor]--;
            
            if(in_degree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }
    
    if(answer.size() != n) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    
    for(auto element: answer){
        cout << element << " ";
    }

    return 0;
}