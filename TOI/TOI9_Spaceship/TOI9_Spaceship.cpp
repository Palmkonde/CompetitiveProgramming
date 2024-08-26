#include<bits/stdc++.h>
using namespace std;


struct pos
{
    int x,y,z;
    int M,K,CPU;
    bool visited=false;
    
    pos(int a,int b,int c)
    {
        x = a;
        y = b;
        z = c;
        M = K = CPU = 0;
    }

    pos()
    {
        x = y = z = 0;
        M = K = CPU = 0;
    }

    void add(int a,int b, int c)
    {
        M += a;
        K += b;
        CPU += c;
    }

    void del(int a,int b, int c)
    {
        M -= a;
        K -= b;
        CPU -= c;
    }

    bool want(int n)
    {
        
        return (M >= n and K >= n and CPU >= n);
    }
};

int n,a,b,c,q;
int d,e,f;
pos node[15];  
int64_t ans=INT_MAX;

ostream &operator << (ostream &output, pos &a)
{
    return output << "position -> " << a.x 
                            << " "  << a.y 
                            << " "  << a.z;
}

long long cal(pos &a, pos &b)
{
    return ((a.x-b.x)*((a.x-b.x)))+((a.y-b.y)*((a.y-b.y)))+((a.z-b.z)*((a.z-b.z)));
}

void dfs(pos &now,int64_t dist,pos &temp)
{
    //cout << now << " " << dist << "\n";
    if(temp.want(n))
    {
        //cout << "->"<<temp.M << " " << temp.K << " " << temp.CPU << "\n";
        ans = min(dist,ans);
        return;
    }
    
    for(int i=0;i<=q;i++)
    {
        if(node[i].visited) continue;
        node[i].visited = true;
    
        int next = dist+cal(now,node[i]);
        temp.add(node[i].M,node[i].K,node[i].CPU);
    
        dfs(node[i],next,temp);
    
        node[i].visited = false;
        temp.del(node[i].M,node[i].K,node[i].CPU);    
    }
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cin >> a >> b >> c;

    node[0] = pos(a,b,c); //start
    
    cin >> q;
    for(int i=1;i<=q;i++)
    {
        cin >> a >> b >> c >> d >> e >> f;
        node[i] = pos(a,b,c);
        node[i].add(d,e,f);
    }

    dfs(node[0],0,node[0]);
    
    cout << ans;
    return 0;
}

/*
1
0 0 0
2
10 0 0
2 5 7 
0 10 0
0 3 9
*/
/*
5
0 0 0
5
60 34 56 
0 5 7 
90 41 92 
1 7 8 
24 61 81 
6 8 8 
41 86 70 
5 6 7 
46 97 85 
9 2 4
*/