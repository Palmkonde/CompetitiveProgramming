#include<stdio.h>
#define ll long long

int n;
ll a1[500005],a2[500005];
ll ans[500005];

void Msort(int l,int r, ll *arr, char state)
{
    if(l >= r) return;
    
    int mid = l+(r-l)/2;
    Msort(l,mid,arr,state);
    Msort(mid+1,r,arr,state);

    int n1 = mid-l+1;
    int n2 = r-mid;
    
    ll t1[n1],t2[n2];

    for(int i=0;i<n1;i++) t1[i] = arr[l+i];
    for(int i=0;i<n2;i++) t2[i] = arr[mid+i+1];

    int i,j,k;
    i = j = 0;
    k=l;

    while(i<n1&&j<n2)
    {
        if(state)
        {
            if(t1[i] < t2[j]) arr[k++] = t1[i++];
            else arr[k++] = t2[j++];
        }
        else
        {
            if(t1[i] > t2[j]) arr[k++] = t1[i++];
            else arr[k++] = t2[j++];
        }
    }

    while(i<n1) arr[k++] = t1[i++];
    while(j<n2) arr[k++] = t2[j++];
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%lld",&a1[i]);
    for(int i=0;i<n;i++) scanf("%lld",&a2[i]);

    Msort(0,n-1,a1,0);
    Msort(0,n-1,a2,1);

    for(int i=0;i<n;i++) ans[i] = a1[i]+a2[i];

    Msort(0,n-1,ans,1);

    printf("%lld",ans[n-1] - ans[0]);

    return 0;    
}