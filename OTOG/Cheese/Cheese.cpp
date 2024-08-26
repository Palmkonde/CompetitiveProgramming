#include<bits/stdc++.h>
using namespace std;

int cheese[10005];
int n,s;
int dp[10005][102];

int ch(int now, int s)
{
    //base case
    if(now >= n) return 0;
    int res = 0;
    if(dp[now][s]) return dp[now][s];

    //ใช้ยาสลบ
    if(s > 0)
    {
        res = max(ch(now+1,s-1)+cheese[now],ch(now+2,s-1)+cheese[now]);
        //ใช้ยาสลบวันนี้แล้วใช้วนัถัดไป กับใช้ยาสลบวันนี้แล้วหนี้วันถัดไป   
    }

    //ไม่ใช้ยาสลบ
    res = max(ch(now + 2,s)+cheese[now],max(ch(now+1,s),res));

    

    return dp[now][s] = res;
}

int main()
{
    cin >> n >> s;

    for(int i=0;i<n;i++) cin >> cheese[i];

    cout << ch(0,s); //state ยาสลบ

    return 0;
}
/*
ใช้ยาสลบ --> ใช้ยาสลบวันนี้แล้วใช้วนัถัดไป กับใช้ยาสลบวันนี้แล้วหนี้วันถัดไป   
ขโมยวันนี้ --> ได้ชีสวันนี้  ต้องขโมย 2 วันถัดไป ยาสลบเท่าเดิม
ขโมยวันถัดไป --> ไม่ได้ชีสวันนี้ ขโมยวันถัดไป ยาสลบเท่าเดิม
*/