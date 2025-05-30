#include<bits/stdc++.h>
using namespace std;

int n, m;
queue<pair<int, int>> q;
int main() {
    cin.tie(NULL)->sync_with_stdio(false);
    
    cin >> n >> m;

    int x;
    for(int i=1; i<=n; i++) {
        cin >> x;
        q.push({x, i});
    }
    
    while(q.size() != 1) {
    
        int now = q.front().first;
        int idx = q.front().second;
        q.pop();

        if(now - m <= 0) continue;
        
        q.push({now - m, idx});
    }

    cout << q.front().second;
    return 0;
}