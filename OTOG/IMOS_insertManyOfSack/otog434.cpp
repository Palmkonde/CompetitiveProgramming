#include<bits/stdc++.h>
using namespace std;

const int N = 6000;

int mp[N][N];
int r,c,q;

void update(pair<int,int>st, pair<int,int>ed,int w)
{
    //topleft
    mp[st.first][st.second] += w;

    //topright +1
    mp[st.first][ed.second+1] += -w;

    //botleft+1
    mp[ed.first+1][st.second] += -w;

    //botright+1+1
    mp[ed.first+1][ed.second+1] += w;
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> r >> c;
    cin >> q;

    while(q--)
    {
        int x,y,a,b,v;
        cin >> x >> y >> a >> b >> v;
        update({x,y},{a,b},v);
    }

    int temp = 0;
    for(int i = 1; i < r+5;i++)
    {
        for(int j=1;j< c+5;j++)
        {
            temp += mp[i][j];
            mp[i][j] = temp;
        }
    }
    temp = 0;

    for(int i = 1; i < c+5;i++)
    {
        for(int j=1;j< r+5;j++)
        {
            temp += mp[j][i];
            mp[j][i] = temp;
        }
    }

    cout << "\n";

    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
            cout <<mp[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}

/*
10 10
10
3 3 5 8 19
2 4 5 8 49
8 3 10 10 34
7 6 8 8 12
9 3 10 3 12
3 2 5 5 33
1 3 9 5 26
3 8 9 9 36
7 1 7 5 36
7 6 10 10 13
*/