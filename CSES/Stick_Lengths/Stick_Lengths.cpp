#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, p;
int pi[N];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &pi[i]);
    }

    sort(pi, pi + n);

    // หามัธยฐานเพื่อที่ว่าจะเป็นค่ากลางที่เพิ่มหรือลดได้อย่างน้อยที่สุด
    int median = pi[n / 2];

    int64_t ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += abs(pi[i] - median);
    }

    printf("%lld", ans);

    return 0;
}