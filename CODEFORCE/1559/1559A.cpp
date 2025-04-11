// https://codeforces.com/contest/1559/problem/D1
#include<bits/stdc++.h>
using namespace std;

const int N = 1005;
const int M = 10005;

struct Edge {
    map<pair<int, int>, int> mp;
    
    void addEdge(int u, int v) {
        if(u > v) swap(u, v);
        
        mp[{u, v}] = 1;
    }
    
    int get(pair<int, int> p){
        return mp[p];
    }
};

struct Forest {
    int n;
    int parent[N];
    int number_of_node[N];
    
    Forest(int x) {
        this->n = x;
        fill(this->parent, this->parent + N, -1);
        fill(this->number_of_node, this->number_of_node + N, 1);
    }

    int root(int x) {
        if(this->parent[x] == -1) return x;

        return this->parent[x] = root(this->parent[x]);
    }
    
    void print_parent() {
        for(int i=1; i<=n; i++) {
            cout << this->parent[i] << " ";
        }
        cout << "\n";
    }
};

void union_components(int u, int v, Forest *f) {
    int pa = f->root(u);
    int pb = f->root(v);
   
    if(pa != pb) {     
        if(f->number_of_node[pa] > f->number_of_node[pb]) swap(pa, pb);

        f->parent[pa] = pb;
        f->number_of_node[pb] += f->number_of_node[pa];
    }
}

int main() {
    int n, m1, m2;
    int u, v;
    Edge edge_list;

    cin >> n >> m1 >> m2;
    
    Forest *Mocha, *Diana;
    Mocha = new Forest(n);
    Diana = new Forest(n);
    
    for(int i=0; i<m1; i++) {
        cin >> u >> v;
        union_components(u, v, Mocha);
        edge_list.addEdge(u, v);
    }

    for(int i=0; i<m2; i++) {
        cin >> u >> v;
        union_components(u, v, Diana);
        edge_list.addEdge(u, v);
    }
    
    // Mocha->print_parent();
    // Diana->print_parent();
    
    // for(auto e: edge_list.mp) {
    //     cout << e.first.first << " " << e.first.second << "\n";
    // }
    
    Edge answer;

    for(int i=1; i<=n; i++) {
        for(int j=i+1; j<=n; j++) {
            if(edge_list.get({i, j})) continue;
            int Mpa = Mocha->root(i);
            int Mpb = Mocha->root(j);

            int Dpa = Diana->root(i);
            int Dpb = Diana->root(j);
            
            if((Mpa != Mpb) && (Dpa != Dpb)) {
                answer.addEdge(i, j);
                
                union_components(i, j, Mocha);
                union_components(i, j, Diana);
            }
        }
    }
    
    cout << answer.mp.size() << "\n";
    for(auto i: answer.mp) {
        cout << i.first.first << " " << i.first.second << "\n";
    }
    
    return 0;    
}