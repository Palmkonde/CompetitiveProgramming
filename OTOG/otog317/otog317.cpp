#include<bits/stdc++.h>
using namespace std;

int n,m;
int d[10];
vector<vector<int>> ans;

void dp(int now, vector<int> &tmp)
{
    if(now < 0 or now > n) return;
    if(tmp.size() > m) return;
    if(now == n)
    {
        // for(auto e:tmp) printf("%d ",e);
        ans.push_back(tmp);
        return;
    }

    for(int i=1;i<=6;i++)
    {
        tmp.push_back(d[i]);
        dp(now+d[i], tmp);
        tmp.pop_back();
    }
}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=6;i++) scanf("%d",&d[i]);

    vector<int> tmp;
    dp(0,tmp);
    
    printf("%d\n",ans.size());
    
    for(auto e:ans)
    {
        printf("E\n%d ",e.size());
        for(auto i:e)
        {
            printf("%d ",i);
        }
        printf("\n");
    }
    printf("E");

    return 0;
}