#include<bits/stdc++.h>
using namespace std;

int n;
int nums[10005];

int main()
{
    cin >> n;

    for(int i=0;i<n;i++)
    {
        cin >> nums[i];
    }

    int b1=0,b2=0;

    for(auto e:nums)
    {
        int temp = max(b1+e, b2);
        b1 = b2;
        b2 =temp;
    }

    cout << b2;

    return 0;
}