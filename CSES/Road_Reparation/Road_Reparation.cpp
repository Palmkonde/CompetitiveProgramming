#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;

const int N = 1e5 + 5;

struct Edge {
    int u, v, w;
};

int n, m;
int parent[N];
ll cost;
vector<Edge> edges;

int root(int x) {
    if(-1 == parent[x]) return x;
    
    return parent[x] = root(parent[x]);
}

int main() {
    scanf("%d%d", &n, &m);

    int u, v, w; 
    for(int i=0; i<m; i++) {
        scanf("%d%d%d", &u, &v, &w);
        edges.push_back({u, v, w});
    }
    
    fill(parent, parent + N, -1);
    
    sort(edges.begin(), edges.end(), [](Edge &a, Edge &b){
        return a.w < b.w;
    });
    
    int comp = n;
    
    for(auto &edge: edges) {
        int pu = root(edge.u);
        int pv = root(edge.v);
        
        if(pu != pv) {
            parent[pv] = pu;
            cost += edge.w; 
            comp--;
        }
    }
    
    if(comp != 1) {
        printf("IMPOSSIBLE");
        return 0;
    }
    printf("%lld", cost);
    
    return 0;
}