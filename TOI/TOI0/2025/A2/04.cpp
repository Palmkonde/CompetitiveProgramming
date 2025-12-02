#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()

using namespace std;

const int M = 305;

int n;
vector<int> freq(M, 0);
int main() {
    cin.tie(NULL)->sync_with_stdio(false);
    
    cin >> n;
    int x;
    for(int i=1; i<=n; i++) {
        cin >> x;
        freq[x]++;
    }
    
    int max_group = *max_element(all(freq));

    cout << max_group;
}