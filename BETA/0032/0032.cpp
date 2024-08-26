#include<bits/stdc++.h>
using namespace std;

const int N = 1005;

int n;
int a[N];

int main()
{
    cin >> n;
    
    for(int i=0;i<n;i++){cin >> a[i];}
    sort(a,a+n);

    if(!a[0])
    {
        for(int i=0;i<n;i++)
        {
            if(a[i] > 0)
            {
                swap(a[i],a[0]);
                break;
            }
        }
    }
    for(int i=0;i<n;i++) cout << a[i];
    return 0;
}