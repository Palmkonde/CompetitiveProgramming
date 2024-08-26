#include<bits/stdc++.h>
using namespace std;

int n;
int arr[100002];

int dp[100002];

//จากสมการ recur
int recur(int nowPos)
{
    if(dp[nowPos] != 0) return dp[nowPos]; // คำนวณแล้ว(เคยคำนวณ)

    if(nowPos >= n) //base case
    {
        return 0;
    }

    else
    {                       //เก็บต่ำแหน่งปัจุบันแต่ไม่สามารถเก็บอีก 2 ต่ำแหน่งถัดไปได้
        int result = max(recur(nowPos + 3)+arr[nowPos], 
                         recur(nowPos + 1)
                        ); // ไม่เก็บ
        dp[nowPos] = result;
        return result;
    }
}

int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> arr[i];

    cout << recur(2);

    return 0;
}