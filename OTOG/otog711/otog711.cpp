#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using pii = pair<int,int>;
using tii = tuple<int,int,int>;

const int N = 105;

struct pqData
{
    int w,u,v;
};

int n,m,q;
int edge[N];
vector<pqData> pq;
vector<tii> ans;
vector<int> cost;

int main()
{
    scanf("%d %d",&n,&m);

    int u,v,w;
    for(int i=0; i<m; i++)
    {
        scanf("%d %d %d",&u,&v,&w);
        pq.push_back({w,u,v});
    }

    sort(all(pq),[](const pqData &a, const pqData &other)
    {
        if(a.w == other.w)
        {
            if(a.u == other.u)
            {
                return a.v > other.v;
            }
            return a.u > other.u;
        }
        return a.w < other.w;
    });


    int tmp = 0,cnt = 0, mx = INT_MIN;
    for(int i=0; i<pq.size(); i++)
    {
        pqData now = pq[i];

        u = now.u;
        v = now.v;
        cnt++;
        edge[u]++;
        edge[v]++;
        tmp += now.w;

        if(ans.empty())
        {
            mx = max(mx,edge[u]);
            ans.push_back({cnt,min(u,v),edge[u]});
        }
        else
        {
            int old,cn;
            tie(std::ignore,old,cn) = ans.back();

            if(edge[u] > mx)
            {
                if(edge[u] > edge[v])
                {
                    mx = edge[u];
                    ans.push_back({cnt,u,mx});
                }
            }
            else if(edge[v] > mx)
            {
                if(edge[v] > edge[u])
                {
                    mx = edge[v];
                    ans.push_back({cnt,v,mx});
                }
            }
            else if(edge[u] == edge[v] and edge[u] > mx)
            {
                mx = edge[u];
                ans.push_back({cnt,u,mx});
            }
            else ans.push_back({cnt,old,cn});
        }
        cost.push_back(tmp);
    }

    scanf("%d",&q);
    while(q--)
    {
        int x;

        scanf("%d",&x);
        auto it = upper_bound(all(cost),x) - (cost.begin());
        it--;

        if(it < 0)
        {
            printf("0\n0 0\n");
            continue;
        }

        printf("%d\n",get<0>(ans[it]));
        printf("%d %d\n",get<1>(ans[it]), get<2>(ans[it]));

    }

    /*
    for(auto e:ans)
    {
        int a,b,c;
        tie(a,b,c) = e;

        cout << a << " " << b << " " << c << "\n";
    }*/

    /*
    for(auto e:cost)
    {
        cout << e << " ";
    }
    */

    return 0;
}

/*
6 8
1 2 3
1 3 4
3 4 5
4 5 6
2 6 7
1 5 8
4 2 9
5 6 10
5
0 3 5 13 12
*/
