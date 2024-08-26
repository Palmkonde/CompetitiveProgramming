#include <bits/stdc++.h>
using namespace std;

int num[300002], n;

int checkbit(int pattern)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if ((pattern & num[i]) == pattern)
        {
            cnt++;
        }
    }
    return cnt++;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    int res = 0, cnt;

    for (int bit = 31; bit >= 0; bit--)
    {
        cnt = checkbit(res | (1 << bit));

        if (cnt >= 2)
        {
            res = res | (1 << bit);
        }
    }

    cout << res;

    return 0;
}

/*
https://www.geeksforgeeks.org/maximum-value-pair-array/
*/
