#include<bits/stdc++.h>
using namespace std;

int q;

int main()
{   
    scanf("%d",&q);

    int n;
    while(q--)
    {
        scanf("%d",&n);

        int mx = n*(n-1);
        int tmp = 0, a;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a);

            if(a >= n)
            {
                printf("No");
                goto skip;
            }
            tmp += a % 2;
        }

        // if(tmp > mx) printf("No");
        if((tmp & 1)) printf("No");
        else printf("Yes");

        skip:
        printf("\n");
    }

    return 0;
}