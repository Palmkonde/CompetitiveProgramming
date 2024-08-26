#include<bits/stdc++.h>
using namespace std;

const int N = 200005;

string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string k;
int shit[N];

int main()
{
    
    cin >> k;
    for(int i=0;i<k.size();i++) cin >> shit[i];

    for(int i=0;i<k.size();i++)
    {
        printf("%c",k[i]);
        for(int j=i+1;j<k.size();j++)
        {
            printf(" %c,%d", k[j],abs(k[i]-k[j]));
        }
        printf("\n");
    }

    
    for(int i=0;i<k.size();i++)
    {
        cout << k[i] << " ";
        for(int j=1;j<=12;j++)
        {
            printf("%c ",alpha[((k[i] - 'A') + shit[i]*j)%26]);
        }
        printf("\n");
    }

    return 0;
}