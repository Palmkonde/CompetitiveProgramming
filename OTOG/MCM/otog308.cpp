#include<bits/stdc++.h>
using namespace std;

const int N = 102;

int n;
int scale[N];
int dp[N][N];

int mcm(int i, int j)
{
    int res = INT_MAX;
    if(i == j) return 0;
    if(dp[i][j]) return dp[i][j];

    for(int k=i;k<=j-1;k++)
    {
        res = min(res, 
                    mcm(i,k)+
                    mcm(k+1,j)+
                    scale[i-1]*scale[k]*scale[j]
                 );    
    }

    return dp[i][j] = res;

}

int main()
{
    scanf("%d",&n);

    for(int i=0;i<=n;i++)
    {
        scanf("%d", &scale[i]);
    }

    printf("%d",mcm(1,n));

    return 0;
}