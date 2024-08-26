#include <bits/stdc++.h>
using namespace std;

int n, q;
int num[505];
int dp[505][22][22];

int paint(int now, int st, int nd)
{
    if (now >= n)
        return 0;

    if (dp[now][st][nd] != -1)
        return dp[now][st][nd];

    int res = INT_MAX;

    //เปลี่ยนแปลงแรก
    if (num[now] != st)
    {
        res = min(res, paint(now + 1, num[now], nd) + 1);
    }

    //แปลงสองคนละสี
    if (num[now] != nd)
    {
        res = min(res, paint(now + 1, st, num[now]) + 1);
    }

    //มีแปลงสีเดียวกับเสา
    if (num[now] == st or num[now] == nd)
    {
        res = min(res, paint(now + 1, st, nd));
    }

    return dp[now][st][nd] = res;
}

int main()
{
    scanf("%d", &q);

    while (q--)
    {
        scanf("%d", &n);

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &num[i]);
        }

        memset(dp, -1, sizeof(dp));
        printf("%d\n", paint(0, 0, 0));
    }

    return 0;
}

/*


สี  1    7    7   8 .... ?


มี 2 แปลง

สี, ระบาย
แปลง 1:  1,1
 "   2:         7,2 7,3

**ไม่รู้ว่าในอนาคตจะเลือกสียังไง**

แปลง
แรก -> 0
สอง -> 0
      ส.1
    (เราไม่รู้ว่าควรเอาแปลงไหน มาจุมสีก่อน เพื่อเอามาทา)

psudocode
ทาสี(เสา , สีของแปลง 1 , สีของแปลง 2 ) = {
                                               สีปัจจุบัน                                  เพราะเราทาสี
                                                 V                                        V
    ลองเปลี่ยนสักแปลง(ลองทั้งสองวิธี)->res =  min(ทาสี(เสา+1, i , เหมือนเดิม), ทาสี(เสา+1, เหมือนเดิม, i)) + 1 ; ทั้งสองแปลงทาสีเสาไม่ได้
    res = ทาสี(เสา + 1, เหมือนเดิม, เหมือนเดิม) ; มีแปลงสักอันที่ทาสีได้
}

อีกวิธี
ทาสี(เสา, สีแปลง 1, สีแปลง 2) //ลองใช้ทั้งสองแปลง
{
    res = INF
     # ลองใช้แปลงที่ 1
     if(สีของแปลง 1 ตรงเสา) # ไม่ต้องจุมใหม่
        res = min(res, ทาสี(เสา+1, เหมือนเดิม , เหมือนเดิม))

     else #คนละสีกำับเสา
      res = min(res, ทาสี(เสา+1, สีเสา, เดิม)) + 1

     #ลองแปลงที่ 2 หลักการเหมือนกัน
}
*/