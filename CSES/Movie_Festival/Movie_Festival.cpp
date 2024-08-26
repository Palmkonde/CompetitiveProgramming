/*
algorithim: Greedy
*/

#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int N = 2e5 + 5;

int n, a, b;

int main()
{
    scanf("%d", &n);

    vector<pii> event(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &a, &b);
        event[i] = {b, a};
    }

    // ทำการ sorting เพื่อที่จะเลือกจุดจบที่มาเร็วที่สุดก่อนจะได้
    // มีตัวเลือกอื่นๆในอนาคต
    sort(event.begin(), event.end());

    int endnow = -1;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        // เช็คว่า event ที่กำลังจะเกิดขึ้นกับที่จบไปแล้ว
        // event ที่กำลังจะเกิดขึ้นมีค่ามากกว่ารึป่าวแล้ว
        // แล้วก็ทำการเลือกเลย
        if (endnow <= event[i].second)
        {
            endnow = event[i].first;
            cnt++;
        }
    }

    printf("%d", cnt);

    return 0;
}