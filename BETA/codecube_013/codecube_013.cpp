#include<bits/stdc++.h>
using namespace std;

const int N = 1005;

int n,k;
int a[N];

int main()
{
    scanf("%d %d",&n,&k);

    int mx = INT_MIN;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        mx = max(a[i],mx);
    }

    int l = mx, r = INT_MAX;
    while(l < r)
    {
        int cnt = 0;
        int sum = 0;
        int mid = l + (r-l)/2;
        for(int i=0;i<n;i++)
        {
            if(sum + a[i] > mid)
            {
                sum = 0;
                cnt++;
            }
            sum += a[i];
        }
        if(sum > 0) cnt++;
        //printf("%d %d %d\n",l,mid,r);

        if(cnt <= k)
        {
            r = mid;
        }
        else l = mid+1;
    }

    printf("%d",l);

    return 0;
}