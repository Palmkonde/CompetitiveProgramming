#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

map<int,vector<pii>> mp = { // p, wat
  {0,{{0,2}}},
  {2,{{0,0},{1,0},{2,1}}},
  {1,{{0,1},{1,1},{1,2},{2,0},{2,2}}} 
};

int n;
string code;
int dp[260][260][3];

bool mcm(int i,int j,int p)
{
  bool res = false;
  if(i == j) return (code[i]-'0' == p);
  if(dp[i][j][p] != -1) return dp[i][j][p];
  else
  {
    for(int k=i;k<=j-1;k++)
    {
      for(auto e: mp[p])
      {
        res = mcm(i,k,e.first) and mcm(k+1,j,e.second);
        if(res) return dp[i][j][p] = res;
      }
    }
  }

  return dp[i][j][p] = res;
}

int main()
{
  cin.tie(0)->sync_with_stdio(false);
  
  int t = 20;
  while(t--)
  {
    cin >> n >> code;
    memset(dp,-1,sizeof(dp));
    if(mcm(0, n-1, 0)) cout << "yes\n";
    else cout << "no\n";
  }

  return 0;
}
/*


// mcm สามารถ generate การใส่วงเล็บได้
        0 2 0 1

ภายในวงเล็บแต่ละวงเล็บมี การเรียกซ้ำๆ
k=1 (0) (201)
k=2 (02)(01)
k=3 (020)(1)
k=4 (0201)

กำหนด state 
ช่วงของสมการ จาก l ถึง r สามารถทำ p ได้หรือป่าว (คำตอบคือ ทำได้หรือไม่ได้)

EX 0 2 0 ทำ 2 ได้หรือเปล่า

วิธีที่จะได้ 2  0,0  1,0  2,1
           ^
mcm        |
 ถามกลับว่า    วงเล็บหน้า หลัง มันทำได้มั้ย
   V
  (0)(20)
  (02)(0)


implement 
def segi(l,r,p) -> return true || false;

*/