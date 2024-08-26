#include<bits/stdc++.h>
using namespace std;

const int N = 15005;

struct point
{
    int x,y;
};

int n,k;
int dist[N];
point pos[N];

int cal(int i,int j)
{
    return abs(pos[i].x - pos[j].x) + abs(pos[i].y - pos[j].y);
}

int main()
{
    scanf("%d%d",&n,&k);
    fill_n(dist,N,INT_MAX);

    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&pos[i].x, &pos[i].y);
    }
    

    for(int i=0;i<n-1;i++)
    {
        int mn = INT_MAX;
        int idx = -1;
        for(int j=i+1;j<n;j++)
        {
            int d = cal(i,j);
            dist[j] = min(dist[j],d);
            
            if(dist[j] < mn) 
            {
                mn = dist[j];
                idx = j;
            }
        }

        swap(dist[i+1],dist[idx]);
        swap(pos[i+1],pos[idx]);
    }

    sort(dist,dist+n);
    int ans = 0;
    for(int i=0;i<n-k;i++) ans += dist[i];
    printf("%d",ans);
    

    return 0;
}