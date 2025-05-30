#include<bits/stdc++.h>
using namespace std;

const int N = 2*1e5 + 5;

vector<long long> arr(N), pf(N);
int n, q, l, r;

int main() {
    cin >> n >> q;
   
    int x;
    for(int i=1; i<=n; i++) {
        cin >> x;
        pf[i] = pf[i - 1] + x;
    }

    while(q--) {
        cin >> l >> r;
        cout << pf[r] - pf[l - 1] << "\n";
    }

    return 0;
}