#include <bits/stdc++.h>
using namespace std;

struct team
{
    string name;
    int shot;
    int losing;
    int score;
};

team foot[4];
string temp[4];
int table[5][5];

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    for (int i = 0; i < 4; i++)
    {
        cin >> temp[i];
        foot[i].name = temp[i];
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> table[i][j];
        }
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (i == j)
                continue;

            if (table[i][j] > table[j][i])
            {
                foot[i].score += 3;
            }
            else if (table[i][j] == table[j][i])
            {
                foot[i].score += 1;
            }

            foot[i].shot += table[i][j];
            foot[j].losing += table[i][j];
        }
    }

    sort(foot, foot + 4, [](const team &a, const team &b)
         {
            if(a.score == b.score)
            {
                if((a.shot - a.losing) == (b.shot - b.losing))
                {
                    return a.shot > b.shot;
                }
                else 
                {
                    return (a.shot - a.losing) > (b.shot - b.losing);
                }
            }
            else 
            {
                return a.score > b.score;
            } });

    for (int i = 0; i < 4; i++)
    {
        cout << foot[i].name << " " << foot[i].score << "\n";
    }

    return 0;
}

/*
Denmark
Netherlands
Cameroon
Japan
0 0 2 1
2 0 2 1
1 1 0 0
3 0 1 0
*/