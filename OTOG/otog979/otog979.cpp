#include<bits/stdc++.h>
using namespace std;
using ld = double;

const int N = 2e5+5;

class Data
{
public:
    int a,b,c;
    Data(int x,int y,int z){a=x,b=y,c=z;}
    Data(){a=b=c=0;}
};

int n,k;
int a,b,c;
Data pos[N];

int main()
{
    scanf("%d%d",&n,&k);

    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        pos[i] = Data(a,b,c);
    }

    ld l=0.00001,r=1;
    while (abs(r-l) > 1e-7)
    {
        ld mid = l + (r-l)/2;
        ld res = 0.0;
        
        // printf("->%lf %lf %lf ",l,r,mid);
        
        for(int i=0;i<n;i++)
        {
            res += double(pos[i].a*mid) + pow(mid, pos[i].b) + pow(mid, pos[i].c);    
        }
        
        // printf("%lf\n",res);

        if(res < k) l = mid+0.00001;
        else r = mid;
    }
    l = ceil(l*10000)/100.0;
    printf("%.2lf",l);

    return 0;
}
/*
4 50
10 1 0
20 1 0
30 1 0
40 1 0
*/