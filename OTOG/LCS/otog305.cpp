#include<bits/stdc++.h>
using namespace std;

string a,b;
int dp[502][502];

int LCS(int i,int j)
{
    int res=0;
    if(i < 0 or j < 0) return 0;
    if(dp[i][j]) return dp[i][j];
    if(a[i] == b[j])
    {
        res = LCS(i-1,j-1)+1;
    }
    else
    {
        res = max(LCS(i-1,j),LCS(i,j-1));
    }

    return dp[i][j] = res;

}

int main()
{
    cin >> a >> b;
    cout << LCS(a.length()-1,b.length()-1);
    return 0;
}