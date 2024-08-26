#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> lang[30005];
int parent[30005];
queue<pair<int,int>> q;

int fine(int x)
{
    if(parent[x] == 0)
    {
        return x;
    }
    return parent[x] = fine(parent[x]);
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> n >> m;

    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin >> x;
        
        if(x == 0) cnt++;
        int temp = 0;
        for(int j=0;j<x;j++)
        {
            int l;
            cin >> l;
            if(j){
                //union
                int pa = fine(l);
                int pb = fine(temp);
                if(pa != pb)
                {
                    parent[pb] = pa;
                }
            }

            temp=l;

        }
    }

    
    for(int i=1;i<=n;i++)
    {
        if(parent[i] == 0)
        {
            cnt++;
        }
    }

    cout << cnt-1;


    return 0;
}
/*

มันลากต่อกัน เราก็ลากคนที่สอนภาษาให้เพื่อนได้ จะออกมาเป็น componentๆ แยกๆกันไป

เราก็จะได้ กลุ่มๆแยกกัน --> เราก็จะสามารถใช้ algo disjoint set มาแก้ได้

นับ component กราฟ แล้วก็ ดูว่าต้องเชื่อมเท่าไหร่

*/