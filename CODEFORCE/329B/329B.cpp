#include<bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, m;
int step_mp[N][N];
int di[4][2] = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0}
};
char mp[N][N];
queue<tuple<int, int, int>> q;

pair<int, int> forest_exit = {-1, -1};

void BFS() {
    while(not q.empty()) {
        int now_x, now_y, step;
        tie(now_x, now_y, step) = q.front();
        q.pop();
        
        if(step_mp[now_x][now_y] != 0) {
            continue;
        }
        printf("->%d %d %d ", now_x, now_y, step);
        step_mp[now_x][now_y] = step;
        printf("<%d>\n", step_mp[now_x][now_y]);
        if(mp[now_x][now_y] == 'E') {
            break;
        }
        
        for(int i=0; i<4; i++) {
            int nx = now_x + di[i][0];
            int ny = now_y + di[i][1];
            int n_cnt = step + 1;
            
            if(nx < 0 or ny < 0 or nx >= n or ny >= m) continue;
            if(mp[nx][ny] == 'T') continue;
            if(step_mp[nx][ny] != 0) continue;
            
            q.push({nx, ny, n_cnt});
        }
    }
}

int main() {
    cin >> n >> m; 

    for(int i=0; i<n; i++) {
        string tmp;
        cin >> tmp;
        for(int j=0; j<m; j++) {
            mp[i][j] = tmp[j];
            
            if(mp[i][j] == 'S') {
                q.push({i, j, 0});
            }
            
            if(mp[i][j] == 'E') {
                forest_exit = {i, j};
            }
        }
    }
    
    BFS();
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout << step_mp[i][j] << " ";
        }
        cout << "\n";
    }
     
}