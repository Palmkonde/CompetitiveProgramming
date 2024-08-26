#include<stdio.h>

int a,b;
char c;

int main()
{
    scanf("%d %c%d",&a,&c,&b);
    
    switch (c)
    {
        case '+': printf("%d",a+b);break;
        case '-': printf("%d",a-b);break;
        case '*': printf("%d",a*b);break;
        case '/': printf("%d",a/b);break;
    }

    return 0;
}