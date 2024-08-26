#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

const int MAXN = 55;

long long dp[MAXN][MAXN];
int n,m,d;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> d;
    for(int i=0;i<d;++i)
    {
        int a,b;
        cin >> a >> b;
        dp[b][a] = -1;
    }

    dp[1][1] = 1;
    swap(n,m);
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(i==1 and j == 1) continue;
            if(dp[i][j] == -1) dp[i][j] = 0;
            else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

 

    cout << dp[n][m];

    return 0;
}