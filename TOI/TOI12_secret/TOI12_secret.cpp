#include<bits/stdc++.h>
using namespace std;

const int N = 1005;

string a,b,q;
int n,m,k;
int dp[N][N];

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> a >> b;

    n = a.size();
    m = b.size();
    
    cin >> k;

    while(k--)
    {
        cin >> q;
       
        memset(dp,0,sizeof(dp));
        dp[0][0] = 1;

        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(dp[i][j])
                {
                    if(q[i+j] == a[i]) dp[i+1][j] = true;
                    if(q[i+j] == b[j]) dp[i][j+1] = true;    
                }
            }
            //cout << "\n";
        }

        // for(int i=0;i<=n;i++)
        // {
        //     for(int j=0;j<=m;j++)
        //     {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << "\n";
        // }

        cout << ((dp[n][m]) ? "Yes" : "No") << "\n";
    }

    return 0;
}