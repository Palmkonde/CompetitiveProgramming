#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll N = 2e5 + 5; 

ll n, t;
ll k[N];

int main() {
    scanf("%lld %lld", &n, &t);

    for(int i=0; i<n; i++) scanf("%lld", &k[i]);
    
    sort(k, k+n, greater<ll>());
    
    ll l = 0, r = LLONG_MAX;
    while(l < r) {
        ll mid = l + (r-l)/2;
        
        ll cnt = 0;
        bool f = false;
        for(int i=0; i<n && cnt <= t; i++) {
            cnt += mid/k[i];
        }
        
        if(cnt < t) l = mid + 1;
        else r = mid;
    }
    
    printf("%lld", l);
} 