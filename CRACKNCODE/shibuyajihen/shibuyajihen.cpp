#include<bits/stdc++.h>
using namespace std;

int n;
int main()
{
    scanf("%d",&n);

    int all = 2*n-1;
    for(int i=0;i<all;i++)
    {
        printf("#");
        for(int j=1;j<all;j++)
        {
            if(j == i && i) printf("#");
            else if(j == all-1) printf("#\n");
            else printf(" ");
        }
    }
    return 0;
}