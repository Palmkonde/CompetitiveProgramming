#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

struct Point {
    int xMin, xMax;
};

int n;

unordered_map<int, Point> dia1;
unordered_map<int, Point> dia2;

int main() {
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> n;
    
    int x, y;
    for(int i=0; i<n; i++) {
        cin >> x >> y;

        // diagonal with slope 1 or -1
        int C = x - y; // y = 1x + C
        int D = x + y; // y = -x + D
        

        if(dia1.find(C) == dia1.end()) {
            dia1[C] = {x, x};
        } else {
            dia1[C].xMin = min(dia1[C].xMin, x);
            dia1[C].xMax = max(dia1[C].xMax, x);
        }

        if(dia2.find(D) == dia2.end()) {
            dia2[D] = {x, x};
        } else {
            dia2[D].xMin = min(dia2[D].xMin, x);
            dia2[D].xMax = max(dia2[D].xMax, x);
        }
    }
    
    long long max_side = 0;
    for(const auto &it: dia1) {
        long long side = it.second.xMax - it.second.xMin;
        max_side = max(max_side, side);
    }
    
    for(const auto &it: dia2) {
        long long side = it.second.xMax - it.second.xMin;
        max_side = max(max_side, side);
    }
    
    cout << max_side;
}