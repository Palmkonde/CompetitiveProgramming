#include<bits/stdc++.h>
#define MIN(a,b) (a < b) ? a:b
using namespace std;
using ll = long long;

const int N = 2e5 + 5;

class point
{
public:
    ll x,y;
    point(){x=0,y=0;}
    point(ll a,ll b){x = a,y = b;}
    void display(){printf("x:%lld y:%lld\n",x,y);}
    ll dist(point &other){return abs(this->x - other.x) + abs(this->y - other.y);}
    ll d(point &other){return sqrt(((this->x - other.x)*(this->x - other.x)) +((this->y - other.y)*(this->y-other.y)));}

    bool check(point &center, ll &r)
    {
        return this->d(center) <= r;
    }
};

ll n,x,y,r;
point pos[N];

int main()
{
    scanf("%lld",&n);
    scanf("%lld%lld%lld",&x,&y,&r);

    point center(x,y);

    ll s_mn = LLONG_MAX;
    ll t_mn = LLONG_MAX;

    for(int i=0;i<n;i++)
    {
        scanf("%lld%lld",&x,&y);
        pos[i] = point(x,y);
    }

    for(int i=0;i<n;i++)
    {
        if(pos[i].check(center,r))
        {
            // pos[i].display();
            s_mn = min(pos[0].dist(pos[i]), s_mn);
            t_mn = min(pos[n-1].dist(pos[i]),t_mn);        
            //printf("->%lld %lld\n",s_mn,t_mn);
        }
    }
    
    if(s_mn==LLONG_MAX or t_mn == LLONG_MAX)
    {
        printf("%lld",pos[0].dist(pos[n-1]));
    }
    else printf("%lld",min(pos[0].dist(pos[n-1]),s_mn + t_mn));
    return 0;
}
/*
7
1 2 0
-2 3
1 0
4 3
2 -1
2 3
0 2
2 -1
*/