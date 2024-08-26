#include<bits/stdc++.h>
using namespace std;

const int N = 3002;
const int M = 300002;

struct pqData
{
    int u,v,w;
};

struct cmp
{
    bool operator()(const pqData&a,const pqData &b)
    {
        return a.w > b.w;
    }
};

struct company
{
    int dist;
    int cost;
};

int b,e,n;
priority_queue<pqData, vector<pqData>, cmp> pq;
int parent[N];
int h[N];
company prize[M];


int fine(int x)
{
    if(parent[x] == -1)
    {
        return x;
    }
    else return parent[x] = fine(parent[x]);
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> b >> e;

    memset(parent,-1,sizeof(parent));
    fill(h,h+(b+1),1);

    for(int i=0;i<e;i++)
    {
        int u,v,w,state;
        
        cin >> u >> v >> w >> state;

        if(state == 0)
        {
            pq.push({u,v,w});
        }

        else if(state == 1)
        {
            int pa = fine(u);
            int pb = fine(v);

            if(pa != pb)
            {
                if(h[pa] < h[pb]) swap(pa,pb); //สูงกว่าเป็น pa
                h[pa] += h[pb];

                parent[pb] = pa;
            }
        }
    }

    cin >> n;
    for(int i=0;i<n;i++)
    {
        int dis,cost;
        cin >> dis >> cost;

        prize[i] = {dis,cost};
    }
    sort(prize,prize+n,[](const company &a,const company &b)
    {
       return a.cost < b.cost; 
    });

    int costbound = prize[0].cost ,distbound = prize[0].dist;
    for(int i=1;i<n;i++)
    {
        if(prize[i].cost > costbound and prize[i].dist < distbound)
        {
            prize[i].cost = INT_MAX;
            prize[i].dist = INT_MIN;
        }
        else
        {
            costbound = prize[i].cost;
            distbound = prize[i].dist;
        }
    }

    int ans = 0;
    while(!pq.empty())
    {
        pqData now = pq.top();
        pq.pop();

        int pa = fine(now.u);
        int pb = fine(now.v);
        int w = now.w;

        if(pa != pb)
        {
            for(int i=0;i<n;i++)
            {
                if(prize[i].dist >= w and prize[i].cost != INT_MAX)
                {
                    ans += prize[i].cost;
                    break;
                }
            }

            if(h[pa] < h[pb]) swap(pa,pb);
            h[pa] += h[pb];

            parent[pb] = pa;

        }
    }   

    cout << ans;

    return 0;
}

/*
6 8
0 1 19 0
1 2 50 1
1 3 5 0
2 3 18 0
0 4 32 0
3 4 22 0
2 5 70 0
4 5 20 1
8
5 60
50 200
75 350
20 100
40 145
15 50
35 150
8 60
*/