#include<stdio.h>

int n,q;
int arr[100005];

void Msort(int l,int r)
{
    if(l >= r) return;
    int mid = l+(r-l)/2;
    Msort(l,mid);
    Msort(mid+1,r);

    int n1 = mid-l+1;
    int n2 = r-mid;
    int t1[n1],t2[n2];

    for(int i=0;i<n1;i++) t1[i]=arr[l+i];
    for(int i=0;i<n2;i++) t2[i]=arr[mid+i+1];

    int i=0,j=0,k=l;
    while(i<n1&&j<n2)
    {
        if(t1[i] < t2[j]) arr[k++] = t1[i++];
        else arr[k++] = t2[j++];
    }

    while(i<n1) arr[k++] = t1[i++];
    while(j<n2) arr[k++] = t2[j++];
}

int lw(int l,int r, int tar)
{
    while(l<r)
    {
        int mid = l+(r-l)/2;
        if(arr[mid] < tar) l = mid+1;
        else r = mid;
    }
    return r;
}

int up(int l,int r,int tar)
{
    while(l<r)
    {
        int mid = l + (r-l)/2;

        if(arr[mid] <= tar) l = mid+1;
        else r = mid;
    }
    return r;
}

void swap(int *l,int *r)
{
    int tmp = *l;
    *l = *r;
    *r = tmp;
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    Msort(0,n-1);
    
    // for(int i=0;i<n;i++) printf("%d ",arr[i]);
    // printf("\n");

    scanf("%d",&q);
    while(q--)
    {
        int l,r;
        scanf("%d%d",&l,&r);

        if(l > r) swap(&l,&r);

        int low = lw(0,n,l);
        int h = up(0,n,r);

        //printf("%d %d %d\n",h,low,h-low);
        printf("%d\n",h-low);
    }

    return 0;
}