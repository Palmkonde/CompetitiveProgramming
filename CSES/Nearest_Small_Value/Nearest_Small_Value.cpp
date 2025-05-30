#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n;
int arr[N];
stack<pair<int, int>> st;
int main() {
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> n;

    for(int i=1; i<=n; i++) cin >> arr[i];
    
    vector<int> ans;
    for(int i=1; i<=n; i++) {
        if(st.empty()) {
            st.push({arr[i], i});
            ans.push_back(0);
        }
        else {
            while(!st.empty() && st.top().first >= arr[i]) {
                st.pop();
            }
            
            if(st.empty()) {
                ans.push_back(0);
            }
            else {
                ans.push_back(st.top().second);
            }
            
            st.push({arr[i], i});
            
        }
    }
    for(auto &e: ans) {
        cout << e << " ";
    }
    return 0;
}