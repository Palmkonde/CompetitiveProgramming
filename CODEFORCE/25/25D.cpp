// https://codeforces.com/contest/25/problem/D

#include<bits/stdc++.h>
using namespace std;

const int N = 1005;

struct Road {
    int parent[N];
    
    Road() {
        fill(parent, parent+N, -1);
    }

    int root(int x) {
        if(this->parent[x] == -1) {
            return x;
        }
        
        return this->parent[x] = root(this->parent[x]);
    }
    
    bool union_components(int u, int v) {
        int pa, pb;
        pa = root(u);
        pb = root(v);

        if(pa != pb) {
            if(pa > pb) swap(pa, pb);
            parent[pa] = pb;
            
            return true;
        }
        
        return false;
    
    }
    
    void print(int n) {
       for(int i=1; i<=n; i++){
            cout << parent[i] << " ";
       }
        cout << "\n";
    }
};

int main() {
    int n, u, v;
    Road city;
    vector<pair<int, int>> rebuild;

    cin >> n;
    
    for(int i=0; i<n-1; i++) {
        cin >> u >> v;
        
        if(u > v) swap(u, v);
        if(!city.union_components(u, v)) {
            rebuild.push_back({u, v});
        }
    }
    
    cout << rebuild.size() << "\n";
    for(auto &element: rebuild) {
        cout << element.first << " " << element.second << " ";
        
        bool flag = false;
        for(int i=1; i<=n; i++) {
            if(city.parent[i] != -1) continue;
            
            // printf("Parent before union select i: %d\n", i);
            // city.print(n);
            
            for(int j=i+1; j<=n; j++) {
                if(city.parent[j] != -1) continue;
                
                city.union_components(i, j);
                cout << i << " " << j << "\n";

                // printf("Parent after union select j: %d\n", j);
                // city.print(n);
                break;
            }
        break;
        }
    }
    return 0;
}