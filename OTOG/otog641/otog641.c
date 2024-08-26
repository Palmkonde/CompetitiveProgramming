#include<stdio.h>
#include<math.h>

int arr[100005];
int n,mn,idx;

int main()
{
    mn = 10000000;
    idx = 0;

    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);

    for(int i=0;i<n;i++)
    {
        arr[i] -= i;
        if(arr[i] <= 0){ printf("%d",i+1); return 0;}
        
        int tmp = ceil(arr[i]*1.00/n);
        if(mn > tmp)
        {
            mn = tmp;
            idx = i+1;
        }
    }

    printf("%d",idx);
    
    return 0;
}