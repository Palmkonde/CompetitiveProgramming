#include<bits/stdc++.h>
using namespace std;

const int N = 1000002;

int n;
int64_t room[N];
int64_t dp[N];

int64_t recur(int now)
{
    if(dp[now]) return dp[now];
    if(now > n) return INT64_MAX;
    if(now == n) return 0;
    else
    {
        int64_t result = 1+min(recur(now+room[now]), recur(now+1));
        dp[now] = result;
        return result;
    }
}

int main()
{
    cin >> n;

    for(int i=1;i<=n;i++)
    {
        cin >> room[i];
    }

    cout << recur(1);
    return 0;
}