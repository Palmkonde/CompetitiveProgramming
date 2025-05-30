#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, m, k;
int ap[N], apart[N];

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    
    for(int i=0; i<n; i++) scanf("%d", &ap[i]);
    for(int i=0; i<m; i++) scanf("%d", &apart[i]);
    
    sort(ap, ap + n);
    sort(apart, apart + m);
    
    int h = 0;
    int cnt = 0;
    
    // for(int i=0; i<n; i++) printf("%d ", ap[i]);
    // printf("\n");
    // for(int i=0; i<m; i++) printf("%d ", apart[i]);
    
    for(int i=0; i<m; i++) {
        while(h < n && ap[h]+k < apart[i]) h++;
        if(h == n) break;
        if(abs(ap[h] - apart[i]) <= k) {
            cnt++;
            h++;
        }
    }
    printf("%d", cnt);
    return 0;
}