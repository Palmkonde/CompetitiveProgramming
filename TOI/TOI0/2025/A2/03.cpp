#include<bits/stdc++.h>
using namespace std;

const int N = 1005;

int n;
vector<int> arr(N, 0);
int main() {
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> n;

    for(int i=1; i<=n; i++) {
        cin >> arr[i];
    }
    
    int i=0, j=1, k=2, cnt = 0;
    
    while(j <= n) {
        if(max({arr[i], arr[j], arr[k]}) == arr[j]) {
            cnt++;
        }
        
        i++, j++, k++;
    }
    
    cout << cnt;
    return 0;
}