#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;
using pii = pair<ll,ll>;

const int N = 100005;

ll n,x,h;
ll dx[N],dh[N];

int main()
{
    scanf("%lld",&n);

    for(int i=0;i<n;i++)
    {
        scanf("%lld %lld",&x,&h);
        dx[i] = x;
        dh[i] = h;
    }

    ll mx =dx[0] + dh[0];
    ll pos = 0;
    ll cnt = 0;
    pii ansL,ansR; //cnt position
    for(int i=1;i<n;i++)
    {
        x = dx[i];
        h = dh[i];
        if(mx > x) cnt++;
        else
        {
            if(cnt > ansR.first) ansR = {cnt,pos};
            pos = i;
            cnt = 0;
        }
        mx = (x+h > mx) ? x+h : mx;
    }
    if(cnt > ansR.first) ansR = {cnt,pos};

    mx = dx[n-1] - dh[n-1];
    pos = n-1;
    cnt = 0;
    for(int i=n-2;i>=0;i--)
    {
        x = dx[i];
        h = dh[i];

        if(mx < x) cnt++;
        else
        {
            if(cnt > ansL.first) ansL = {cnt,pos};
            pos = i;
            cnt = 0;
        }
        mx = (x-h < mx) ? x-h : mx;
    }
    if(cnt > ansL.first) ansL = {cnt,pos};

    ansL.second += 1;
    ansR.second += 1;

    if(ansL.first == ansR.first)
    {
        if(ansL.second == ansR.second)
        {
            printf("%lld L",ansL.second);
        }
        else if(ansL.second < ansR.second) printf("%lld L",ansL.second);
        else printf("%lld R",ansR.second);
    }
    else if(ansL.first > ansR.first)
    {
        printf("%lld L",ansL.second);
    }
    else 
    {
        printf("%lld R",ansR.second);
    }

    return 0;
}