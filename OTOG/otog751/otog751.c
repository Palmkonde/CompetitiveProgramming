#include<stdio.h>
#include<string.h>
#define min(a,b) (a<b) ? a:b
char sen[1005];

int main()
{
    scanf("%s",sen);

    int o=0,t=0,g=0;

    for(int i=0;i<strlen(sen);i++)
    {
        o += (sen[i] == 'O');
        t += (sen[i] == 'T');
        g += (sen[i] == 'G');
    }

    o /= 2;

    printf("%d",min(o,min(t,g)));

    return 0;
}