#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

vector<int> parent;
int size_components[N];
int max_size = 0;

int find_set(int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find_set(parent[i]);
}

void unite_sets(int i, int j) {
    int i_id = find_set(i);
    int j_id = find_set(j);
    if (i_id != j_id) {
        if(size_components[i_id] > size_components[j_id]) swap(i_id, j_id);
        
        size_components[j_id] += size_components[i_id];
        parent[i_id] = j_id;
        
        max_size = max(size_components[j_id], max_size);
    }
}

int main() {
    int n, m, u, v;
    cin >> n >> m;

    parent.resize(n + 1);
    fill(size_components, size_components+N, 1);
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }

    int components = n;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        int root_u = find_set(u);
        int root_v = find_set(v);
        if (root_u != root_v) {
            unite_sets(u, v);
            components--;
        }
        cout << components << " " << max_size << "\n";
    }


    return 0;
}