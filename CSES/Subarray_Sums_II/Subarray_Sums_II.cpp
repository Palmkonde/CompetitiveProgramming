#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, x;
int64_t arr[N];
map<int64_t, int> sums;

int main()
{
    scanf("%d%d", &n, &x);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &arr[i]);
    }
    sums[0] = 1;

    int64_t qs = 0;
    int64_t ans = 0;

    for (int i = 1; i <= n; i++)
    {
        qs += arr[i];
        ans += sums[qs - x];

        sums[qs]++;
    }

    return 0;
}
/*
2 -1 3 5 -2

qs = 2 1 4 9 7

sums[0] = 1
ans += sums[2-7] ; ans = 0, sums[2] += 1
ans += sums[1-7] ; ans = 0, sums[1] += 1
ans += sums[4-7] ; ans = 0, sums[4] += 1
ans += sums[9-7] --> sums[2] ; ans = 1, sums[9] += 1

ค่อยๆ track  qs ทีละตัวไปเรื่อยๆแล้วหาว่า
qs ก่อนหน้านี้ที่ลบกันแล้วได้ x มีรึยังถ้ามีแล้วก็ให้ ans บวกเรื่อยๆ
*/