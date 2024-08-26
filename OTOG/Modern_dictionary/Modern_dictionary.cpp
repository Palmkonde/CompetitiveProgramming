//ติดไรวะแม่งเอ้ย

#include<bits/stdc++.h>
using namespace std;

const int N = 102;
const int M = 27;

string word[N];
map<char,vector<char>> mp;
map<char,int> indge;
queue<char> q;
vector<char> answer;
int n;

int main()
{
    cin >> n;
    
    for(int i=0;i<n;i++)
    {
        cin >> word[i];
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<word[i].size();j++)
        {
            indge[word[i][j]] = 0;
        }
    }
    
    for(int i=0;i<n-1;i++)
    {
        int lower = min(word[i].size(),word[i+1].size());
        for(int j=0;j<lower;j++)
        {
            char u = word[i][j];
            char v = word[i+1][j];

            if(u != v)
            {
                mp[u].push_back(v);
                indge[v]++;
                break;
            }
        }
    }

    for(auto it : indge)
    {
        if(it.second == 0) q.push(it.first);
    }

    if(q.size() > 1)
    {
        cout << "?";
        return 0;
    } 
        

    while(not q.empty())
    {
        char now = q.front();
        q.pop();

        answer.push_back(now);

        for(auto next : mp[now])
        {
            indge[next]--;
            if(indge[next] == 0)
            {
                q.push(next);
            }

            if(q.size() > 1)
            {
                cout << "?";
                return 0;
            }
        }
    }
  
    if(mp.size() != answer.size())
    {
        cout << "!";
        return 0;
    }

    for(auto e:answer)
    {
        cout << e;
    }
    return 0;
}