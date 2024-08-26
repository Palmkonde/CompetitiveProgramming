#include<stdio.h>
#include<string.h>
#define max(a,b) (a>b) ? a:b
char s[5000005];

void msort(int l,int r)
{
    if(l >= r) return;
    
    int mid = l+(r-l)/2;
    msort(l,mid);
    msort(mid+1,r);

    int n1 = mid-l+1;
    int n2 = r-mid;

    char t1[n1],t2[n2];
    for(int i=0;i<n1;i++) t1[i] = s[l+i];
    for(int i=0;i<n2;i++) t2[i] = s[mid+1+i];

    int i=0,j=0,k=l;
    while(i<n1&&j<n2)
    {
        if(t1[i] < t2[j]) s[k++] = t1[i++];
        else s[k++] = t2[j++];
    }
    while(i<n1) s[k++] = t1[i++];
    while(j<n2) s[k++] = t2[j++];
}

int main()
{
    scanf("%s",s);
    msort(0,strlen(s)-1);
    
    char f = s[0];
    int cnt = 0;
    int mx = -1;
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i] != f)cnt = 1;
        else cnt++;

        mx = max(mx,cnt);        
        f = s[i];
    }

    printf("%d",mx);
    
    return 0;
}