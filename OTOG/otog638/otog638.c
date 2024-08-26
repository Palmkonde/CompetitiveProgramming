#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N (int)1e5+5

int n,len;

int main()
{
    scanf("%d%d",&n,&len);

    while(n--)
    {
        char a[N],b[N];
        scanf("%s%s",a,b);

        if(strlen(b) > len) printf("X ");
        else if(strcmp(a,b)==0) printf("P ");
        else printf("- ");
    }

    return 0;
}