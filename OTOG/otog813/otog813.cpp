#include <bits/stdc++.h>
using namespace std;

const int N = 10005;

int n;
int64_t num[N];
int64_t dp[N];

int64_t recur(int now)
{
    if (now >= n)
        return 0;

    if (dp[now])
        return dp[now];

    int64_t res = 0;
    int64_t temp = 0;
    for (int i = 0; i < 3; i++)
    {
        temp += num[now + i];

        for (int j = 2; j <= 4; j++)
        {

            res = max(res, recur(now + i + j) + temp);
        }
    }

    return dp[now] = res;
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    cout << recur(0);

    return 0;
}
/*
DP

เราเริ่มเป็นคนแรก <-- เงื่อนไขโจทย์เพิ่มเติม ลืมเขียนในโจทย์
    เราและลิงจะหยิบได้ 1 ถึง 3

เราจะพิจารณาว่า ตาของเราทำอะไรได้บ้าง
 --> หยิบ 1 ลังบนสุด ได้บนสุด 1 ลัง
 --> หยิบ 2 ลังบนสุด ได้บนสุด 2 ลัง
 --> หยิบ 3 ลังบนสุด ได้บนสุด 3 ลัง

ลิงของเราก็ทำได้ (เวลาที่ลิงหยิบ เราจะไม่ได้แต้ม)

**เราก็ลองดูทุกวิธีแล้วเช็คว่าวิธีไหน ให้ค่า MAX**

สมการ recurence

ส้ม(ลังที่ i)

ส้ม(i) = {

    if(i >= จำนวนลัง) return 0;

    result = 0
    for(เรา = 1-->3) {
        for(ลิง = 1-->3){

            ผลลัพธ์ใหม่ = ผลรวมที่เราหยิบได้
            result = max(result , ส้ม(i + เรา + ลิง ) + ผลลัพธ์ใหม่)

        }
    }

    return result;
}

*/