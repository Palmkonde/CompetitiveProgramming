#include <bits/stdc++.h>
using namespace std;

unordered_map<int64_t, int> mp;

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int n, k;
    string s;

    cin >> n >> k >> s;

    int64_t pref = 0;
    int mx = 0;

    for (int i = 1; i <= n; i++)
    {
        // cout << pref << " ";
        if (s[i - 1] == 'O')
        {
            pref++;
        }
        else
        {
            pref -= k;
        }

        // assign ตำแหน่ง
        if (mp[pref] == 0 and pref != 0) //เช็คดูว่าถ้า prefix มีค่าอะไรสักอย่างแต่ยังไม่ได้อยู่ใน map ก็เอาต่ำแหน่ง i ไป
        {
            mp[pref] = i; // mp[pref] ต่ำแหน่งที่
        }
        else
        {
            mx = max(mx, i - mp[pref]);
        }
    }

    cout << mx;

    return 0;
}

/*
0 -3 -2 -5 -8 -7 -6 -9 -8 -7 -10 -9 -8 -7 -10

mp-> pref, idx

-3 1
-2 2
-5 3
-8 4 <--- 1, 4
-7 5 <--- 2, 5
-6 6
-9 7 <--- 3
-8 8 <--- 1

1.)ช่วง 4 ถึง 8 OOROO O = 4, R = 1, O มากกว่า k เท่าของ R
    ไม่ต้องเปลี่ยนค่าให้ mp[-8] = 8, เพราะถ้าเจอ -8 ในอนาคต mp[-8] = 4 จะมีความยาวมากกว่า

-7 9 <--- 2

2.) ช่วง 5 ถึง 9 OROOR O = 3, R = 2

-10 10 <--- 6
-9 11 <--- 3

3.) ช่วง 7 ถึง 11 OOROO  O = 4, R = 1

-8 12 <--- 4

4.) ช่วง 4 ถึง 12  OOROOROOO O = 7, R = 2

-7 13 <--- 5

5.) ช่วง 5 ถึง 13  OROOROOOR O = 6, R = 3

-10 14 <--- 6

6.) ช่วง 10 ถึง 14 OOORO O = 4, R = 1
*/