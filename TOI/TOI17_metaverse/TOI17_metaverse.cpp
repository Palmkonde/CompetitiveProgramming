#include<bits/stdc++.h>
using namespace std;

const int K = 20005;

struct pos
{
    int inx,iny,oux,ouy;
    
    int dist(pos &other)
    {
        return abs(this->inx - other.inx) + abs(this->iny - other.iny);
    }

    int wrap(pos &other)
    {
        return abs(this->oux - other.inx) + abs(this->ouy - other.iny);
    }

}pos[K];

struct pqData
{
    int w,tick,cur;

    bool operator<(const pqData &other) const 
    {
        if(this->w == other.w)
        {
            return this->tick < other.tick;
        }
        return this->w > other.w;
    }
};


int n,m,k,p;
int dist[K][20]; // start 0, end k+1
priority_queue<pqData> pq;

int main()
{
    scanf("%d%d%d%d",&n,&m,&k,&p);
    
    int a,b,c,d;
    pos[0] = {1,1,0,0};
    pos[k+1] = {n,m,0,0};

    
    for(int i=1;i<=k;i++)
    {
        scanf("%d%d%d%d",&pos[i].inx,&pos[i].iny,&pos[i].oux,&pos[i].ouy);
    }

    fill_n(dist[0],K*20,INT_MAX);
    dist[0][p] = 0;
    pq.push({dist[0][p],p,0});

    while(not pq.empty())
    {
        pqData now = pq.top();
        pq.pop();

        if(dist[now.cur][now.tick] < now.w) continue;

        if(now.cur == k+1)
        {
            printf("%d %d",now.w,p-now.tick);
            return 0;   
        }

        int nw;
        for(int i=0;i<=k+1;i++)
        {
            if(now.cur == i) continue;
        
            if(now.cur != 0 or now.cur != k+1)
            {
                if(now.tick > 0)
                {
                    nw = pos[now.cur].wrap(pos[i]);
                    if(dist[i][now.tick-1] > dist[now.cur][now.tick] + nw)
                    {
                        dist[i][now.tick-1] = dist[now.cur][now.tick] + nw;
                        pq.push({dist[i][now.tick-1], now.tick-1,i});
                    }
                }
            }

            nw = pos[now.cur].dist(pos[i]);
            if(dist[i][now.tick] > dist[now.cur][now.tick] + nw)
            {
                dist[i][now.tick] = dist[now.cur][now.tick] + nw;
                pq.push({dist[i][now.tick],now.tick,i});
            }
        }
    }
    return 0;
}