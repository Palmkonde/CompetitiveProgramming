#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 5;

ll n, k;
ll x[N];

bool is_possible(const ll max_sum) {
    ll groups = 1;
    ll sums = 0;
    for(int i=0; i<n; i++) {
        if(x[i] > max_sum) return false;
        
        if(sums + x[i] > max_sum) {
            groups++;
            sums = x[i];
        }
        else {
            sums += x[i];
        }
    }
    
    return groups <= k;
}

int main() {
    cin.tie(NULL)->sync_with_stdio(false);
    scanf("%lld%lld", &n, &k);
    
    for(int i=0; i<n; i++) scanf("%lld", &x[i]);

    ll l = 0, r = 0;
    for(int i=0; i<n; i++) r += x[i];
    
    while(l < r) {
        ll mid = l + (r-l)/2;
        
        // printf("Mid: %d\n", mid);
        
        if(is_possible(mid)) r = mid; 
        else l = mid + 1;
        
    }
    
    printf("%lld", l);
    return 0;
}

/*
5 3
2 4 7 3 5
*/