#include<stdio.h>
#include<stdlib.h>
#define N 105
#define INT_MIN -(1<<30)
#define max(a,b) (a > b) ? a : b

int arr[N];

int main()
{
    int n;
    int mx = INT_MIN,cnt=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    for(int i=0;i<n;i++) mx = max(arr[i],mx);
    for(int i=0;i<n;i++) cnt += (arr[i] == mx);
    printf("%d",cnt);
    return 0;
}