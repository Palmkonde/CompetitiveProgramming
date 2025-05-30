#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 5e4 + 5;

int n;
ll arr[N], pf[N];

int main() {
    ifstream fin("div7.in");
    ofstream fout("div7.out");
    
    fin >> n;
    
    for(int i=1; i<=n; i++) {
        fin >> arr[i];
        pf[i] = (pf[i-1] + arr[i])%7;
    }
    
    // principle (pf[j] - pf[i]) % 7 == 0 don't know how
    int right[10], left[10];
    for(int i=1; i<=n; i++) {
        right[pf[i]] = i;
    }
    
    for(int i=n; i>0; i--) {
        left[pf[i]] = i;
    }
    
    int ans = 0;
    for(int i=0; i<7; i++) {
       ans = max(ans, right[i] - left[i]);
    }
    
    fout << ans;
    return 0;
}