#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using pii = pair<int,int>;

int t,q;
map<vector<pii>,int> mp;

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
 
    cin >> t >> q;

    int u,v,n;
    for(int i=0,idx=0;i<t;i++)
    {
        cin >> n;

        vector<pii> tmp;
        for(int j=1;j<n;j++)
        {
            cin >> u >> v;

            if(u > v) swap(u,v);
            tmp.push_back({u,v});
        }   
        sort(all(tmp));
        mp[tmp]++;
    }

    while(q--)
    {
        cin >> n;

        vector<pii> tmp;
        for(int i=1;i<n;i++)
        {
            cin >> u >> v;

            if(u > v) swap(u,v);
            tmp.push_back({u,v});
        }
        sort(all(tmp));
        cout << mp[tmp] << "\n";
    }
    
    return 0;
}