#include<bits/stdc++.h>
using namespace std;

const int N = 1000002;

int s1[N];
int n,what;
int cnt[N]; // shift กี่ครั้ง
int pos[N]; // เลขต้นแบบ ตัวเลข,ต่ำแห่น่ง
int mx = INT_MIN;
int nn = 0;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&s1[i]);
        pos[s1[i]] = i;
    }

    for(int i=0;i<n;i++)
    {
        scanf("%d",&what);
        int temp = ((n+i)-pos[what])%n; // ค้อง shift กี่ครั้ง

        cnt[temp]++;
    }    

    mx = *max_element(cnt,cnt+n);
    nn = max_element(cnt,cnt+n)-cnt;
    printf("%d %d",mx,nn);

    return 0;
}

/*
4
1 3 4 2
1 3 2 4
*/