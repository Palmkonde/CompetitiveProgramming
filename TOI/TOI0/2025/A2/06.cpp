#include<bits/stdc++.h>
using namespace std;

int n;
string s;
int mp[35][35];
int main() {
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> n;

    for(int i=1; i<=n; i++) {
        cin >> s; 
        
        for(int j=1, k=0; j<=n; j++, k++) {
            mp[i][j] = (s[k] == 'X' ? -1 : 0);
        }
    }
    
    // for(int i=1; i<=n; i++) {
    //     for(int j=1; j<=n; j++) {
    //         cout << mp[i][j];
    //     }
    //     cout << "\n";
    // }

    int cnt = 0;
    mp[n][n] = 1;
    for(int i=n; i>0; i--) {
        for(int j=n; j>0; j--) {
            if(mp[i][j] == -1) continue;
            cnt += mp[i][j];

            if(mp[i][j] == 1) {
                if(mp[i-1][j] != -1) mp[i-1][j] = 1;
                
                if(mp[i][j-1] != -1) mp[i][j-1] = 1;
            }
        }
    }
    
    // for(int i=1; i<=n; i++) {
    //     for(int j=1; j<=n; j++) {
    //         cout << mp[i][j];
    //     }
    //     cout << "\n";
    // }
    cout << cnt;
    return 0;
}