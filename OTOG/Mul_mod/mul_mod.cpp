#include<bits/stdc++.h>
using namespace std;

int64_t mod(int64_t a, int64_t b, int64_t m)
{
    int64_t res = 0;

    a%=m;

    while(b)
    {
        if(b & 1)
            res = (res+a)%m;

        a = (2*a)%m;
        b >>= 1;
    }
    return res;
}

int main()
{
    uint64_t a,b,c;

    while(cin >> a >> b >> c)
    {
        cout << mod(a,b,c) << "\n";
    }

    return 0;
}