#include<bits/stdc++.h>
#define uint64_t unsigned long long

using namespace std;

const int N = 1000005;

uint64_t n,m;
uint64_t num[N];

int main()
{
    scanf("%llu %llu", &m, &n);

    for(int i=0;i<m;i++)
    {
        scanf("%d", &num[i]);
    }

    uint64_t l = 0, r = ULLONG_MAX; //ช่วงเวลาที่ทำงานเสร็จ
    while(l < r)
    {
        uint64_t mid = l+(r-l)/2; //mid เวฃาที่มี
        uint64_t total = 0;
        for(int i=0;i<m;i++)
        {
            total += mid/num[i];
        }

        if(total < n) l = mid+1;
        else r=mid;
    }

    printf("%llu",l);

    return 0;
}

/*
binary search ให้หา..


*/