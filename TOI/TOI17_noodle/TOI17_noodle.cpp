#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

const int N = 100005;

int n,m,k;
int a[N];

bool check(int &mid)
{
    priority_queue<int,vector<int>,greater<int>> pq;

    int sum = 0;
    int cnt = 0;
    for(int i=0;i<n;i++)
    {
        sum += a[i];
        pq.push(a[i]);

        if(pq.size() > k)
        {
            sum -= pq.top();
            pq.pop();
        }

        if(pq.size() == k and sum > mid) // why something wried 
        {
            sum = 0;
            cnt++;

            while(not pq.empty()) pq.pop();
        }
    }
    return cnt < m;
}

int main()
{
    scanf("%d%d%d",&n,&m,&k);

    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    int l = 0, r = INT_MAX;
    while(l < r)
    {
        int mid = l + (r-l)/2;
        
        
        if(check(mid))
        {
            r = mid;
            
        }else l = mid+1;

    }

    printf("%d",r);

    return 0;
}