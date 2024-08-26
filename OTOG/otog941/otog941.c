#include<stdio.h>

int n,q;
int qs[100005];

void mSort(int start,int end)
{
    if(start >= end) return;

    int mid = start + (end-start)/2;
    mSort(start,mid);
    mSort(mid+1,end);

    int n1 = mid-start+1;
    int n2 = end-mid;
    int t1[n1],t2[n2];

    for(int i=0;i<n1;i++) t1[i] = qs[start+i];
    for(int j=0;j<n2;j++) t2[j] = qs[mid+j+1];

    int i,j,k;
    i=j=0;
    k=start;

    while(i < n1 && j < n2)
    {
        if(t1[i] > t2[j]) qs[k++] = t1[i++];
        else qs[k++] = t2[j++];
    }

    while(i<n1) qs[k++] = t1[i++];
    while(j<n2) qs[k++] = t2[j++];
}

int main()
{
    scanf("%d%d",&n,&q);

    for(int i=1;i<=n;i++) scanf("%d",&qs[i]);
    mSort(1,n);for(int i=1;i<=n;i++) qs[i] += qs[i-1];

    int tmp;
    while(q--)
    {
        scanf("%d",&tmp);

        int l=0,r=n+1;
        while(l<r)
        {
            int mid = l+(r-l)/2;

            //printf("%d %d %d\n",l,r,qs[mid]);

            if(qs[mid] < tmp) l=mid+1;
            else r = mid;
        }

        (l > n) ? printf("NO\n") :printf("%d\n",l);
    }   


    return 0;
}