#include<bits/stdc++.h>
using namespace std;

int64_t dp[102][102]; // l,r มีการเรียก l และ r
int rock[102];
int n;

int64_t recur(int l, int r)
{
    if(l > r or l < 0 or l >= 2*n or r < 0 or r >= 2*n)
    {
        return 0;
    }    
    
    if(dp[l][r] != 0) return dp[l][r];
    
    else
    {
        int64_t result = max(recur(l+1, r-1) + rock[l], 
                     max(recur(l+1, r-1) + rock[r], 
                     max(recur(l+2, r) + rock[l],
                         recur(l, r-2) + rock[r] )));

        dp[l][r] = result;
        return result;
    }
}

int main()
{
    cin >> n;
    for(int i=0;i<2*n;i++)
        cin >> rock[i];

    cout << recur(0,(2*n)-1);

    return 0;
}
/*
3
1 2 102 103 3 101
*/