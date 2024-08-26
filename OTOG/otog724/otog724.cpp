// ยังไม่แก้

#include <bits/stdc++.h>
using namespace std;

const int N = 200002;

int n, m, c;
vector<int> adj[N];
bool visited[N];
int indegree[N];

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> m >> c;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;
    }

    return 0;
}

/*
แนวคิด

op   node   day
2     4      1
1     2      2 <--- ปิด
2     4      3
2     3      4
2     5      5
1     3      6 <--- ปิด
2     4      7
2     3      8

djikstra เวลาที่ดีที่สุดที่ผ่านได้เป็นเท่าไหร่
ตอนแรกเป็น INF

ได้ 10 เพราะเราทำ 1 ไปโหนด ใดๆได้  <--- ทำ เก็บไว้ใน d[]
             แต่เรายังไม่รู้ว่า โหนดใดๆไปโหนด N

             เราสามารถ reverse graph แล้ว จาก N ไปโหนด ใดๆ <-- ทำ เก็บไว้ใน rd[]

คำตอบคือ d[],rd[] > x จะไปได้

pq sort จากมากไปน้อย
เวลาอัพพเดตค่า
1 ---> 2
        closetine[2] = 3

    min(เวลาปัจจุบัน,เวลาปิดโหนด ถัดไป) <-- วิเคราะห์ path
    เก็บเข้า d[] = max(dเดิม,dใหม่)

closttine[1] = 10
คือเวลาที่ปิด

*/