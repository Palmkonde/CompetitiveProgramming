#include<bits/stdc++.h>
using namespace std;

string s;
stack<int> index;
int main() {
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> s;
    
    int max_len = -1, start_index = -1;
    index.push(-1);
    for(int i=0; i<s.size(); i++) {
        if(s[i] == '(') {
            index.push(i);
        }
        
        else {
            index.pop();
            if(index.empty()) {
                index.push(i);
            }
            
            else {
                int len = i - index.top();
                
                if(len > max_len) {
                    max_len = len;
                    start_index = index.top() + 1;
                }
            }
        }
    }
    
    if(max_len <= 0) {
        cout << "0 1";
    }

    else {
        cout << max_len << " " << start_index + max_len;
    }
    
    return 0;
}