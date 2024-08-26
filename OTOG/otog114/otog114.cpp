#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 505;

ll dp[N];
int n;
int main()
{
    scanf("%d",&n);

    dp[0] = 1;
    for(int i=1;i<=n;i++)
    {
        for(int j=n;j>=i;j--)
        {
            dp[j] += dp[j-i];
        }
    }

    printf("%lld",dp[n]);

    return 0;
}