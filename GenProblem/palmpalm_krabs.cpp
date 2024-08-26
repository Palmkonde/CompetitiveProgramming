#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 105;
const int M = 1e6+5;
const int T = 1e5+5;

int n,m,s,t,a,b;
ll dp[T][N];

int main()
{
    // freopen("C:\\Users\\USER\\Downloads\\new_tests-20240330T114751Z-001\\new_tests\\3.in","r", stdin);
    // freopen("C:\\Users\\USER\\Downloads\\new_tests-20240330T114751Z-001\\Answer\\3.sol","w",stdout);

    scanf("%d %d %d",&n,&m,&s);

    fill_n(&(dp[0][0]),N*T,-1e8);

    int mxt = -1;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&t,&a,&b);
        dp[t][a] = b; 
        mxt = max(t,mxt);
    }

    dp[0][s] = 0;

    // for(int i=0;i<=mxt;i++)
    // {
    //     for(int j=1;j<=n;j++)
    //     {
    //         printf("%lld ",dp[i][j]);
    //     }
    //     printf("\n");
    // }

    for(int i=1;i<=mxt;i++)
    {
        for(int j=1;j<=n;j++)
        {
            ll mx = max({dp[i-1][j-1],dp[i-1][j],dp[i-1][j+1]});
            if(mx == -1e8)
            {
                dp[i][j] = mx;
                continue;
            }

            if(dp[i][j] == -1e8) dp[i][j] = mx;
            else 
            {
                dp[i][j] = max(dp[i][j], dp[i][j] + mx);
            }
                      
        }
    }

    // printf("\n");
    // for(int i=0;i<=mxt;i++)
    // {
    //     for(int j=1;j<=n;j++)
    //     {
    //         printf("%lld ",dp[i][j]);
    //     }
    //     printf("\n");
    // }

    ll ans = -1;
    for(int i=1;i<=n;i++) ans = max(ans,dp[mxt][i]);
    // for(int i=1;i<=n;i++) printf("%d ",dp[mxt][i]);

    printf("%lld",ans);
    
    //cout << 166561082+578217939+747318886+76050778+818771235;

    return 0;
}
/*
5 3 3
1 2 12
1 4 15
3 1 9
*/