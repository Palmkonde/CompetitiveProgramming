#include <bits/stdc++.h>
using namespace std;

const int N = 105;

struct
{
    int m, p, h; // จำนวนสินค้า, ราคาสินค่า, ค่าพึงพอใจ
} store[N];

int n, x, s, a, b, c;
int dp[1005][105]; // dp[เงิน][ขโมย] = ค่าพึงพอใจ

int main()
{
    scanf("%d %d %d", &n, &x, &s);

    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        store[i] = {a, b, c};
    }

    for (int i = 1; i <= n; i++) // วนตามร้าน
    {
        for (int am = 0; am < store[i].m; am++) // จำนวนชิ้น
        {
            for (int money = x; money >= 0; money--) // เงิน
            {
                for (int mask = s; mask >= 1; mask--) // จำนวนในการขโมย
                {
                    /*
                    เทียบกันระหว่างขโมยกับไม่ขโมย
                    */
                    dp[money][mask] = max(dp[money][mask], dp[money][mask - 1] + store[i].h);

                    /*
                    เทียบกันระหว่างขโมยมาแล้วก็ซื้อด้วย
                    */
                    if (money >= store[i].p)
                    {
                        dp[money][mask] = max(dp[money][mask], dp[money - store[i].p][mask] + store[i].h);
                    }
                }

                // ไม่ขโทยเลย
                if (money >= store[i].p)
                {
                    dp[money][0] = max(dp[money][0], dp[money - store[i].p][0] + store[i].h);
                }
            }
        }
    }

    int ans = INT_MIN, mm = 0;
    for (int i = 0; i <= s; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            if (ans < dp[j][i])
            {
                ans = dp[j][i]; // ค่าพึงพอใจมากสุด
                mm = j;         // จำนวนเงินที่ใช้
            }
        }
    }

    printf("%d %d", ans, x - mm);

    return 0;
}