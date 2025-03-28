#include<stdio.h>
#define N 200005
#define ll long long

int n, m, a, l, r;
ll prefix_sum[N], even[N], odd[N];

int main() {
    scanf("%d %d", &n, &m);

    for(int i=1; i<=n; i++) {
        scanf("%d", &a);
        
        prefix_sum[i] += prefix_sum[i - 1] + a;
        
        if(i % 2 == 0) {
            even[i] += a;
        } else {
            odd[i] += a;
        }
        
        even[i] += even[i - 1];
        odd[i] += odd[i - 1];
    }
    
    for(int i=1; i<=m; i++) {
        scanf("%d%d", &l, &r);
        
        ll ans = (prefix_sum[r] - prefix_sum[l - 1]) - 2 * ((l + 1) % 2 == 0 ? even[r] - even[l - 1] : odd[r] - odd[l - 1]);

        printf("%lld\n", ans);
    }

    return 0;
}