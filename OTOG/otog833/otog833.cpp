#include <bits/stdc++.h>
using namespace std;

string s;
char code[3][3][3][3];

int main()
{
    // 0 '.' , 1 '_'
    code[0][1][2][2] = 'a';
    code[1][0][0][0] = 'b';
    code[1][0][1][0] = 'c';
    code[1][0][0][2] = 'd';
    code[0][2][2][2] = 'e';
    code[0][0][1][0] = 'f';
    code[1][1][0][2] = 'g';
    code[0][0][0][0] = 'h';
    code[0][0][2][2] = 'i';
    code[0][1][1][1] = 'j';
    code[1][0][1][2] = 'k';
    code[0][1][0][0] = 'l';
    code[1][1][2][2] = 'm';
    code[1][0][2][2] = 'n';
    code[1][1][1][2] = 'o';
    code[0][1][1][0] = 'p';
    code[1][1][0][1] = 'q';
    code[0][1][0][2] = 'r';
    code[0][0][0][2] = 's';
    code[1][2][2][2] = 't';
    code[0][0][1][2] = 'u';
    code[0][0][0][1] = 'v';
    code[0][1][1][2] = 'w';
    code[1][0][0][1] = 'x';
    code[1][0][1][1] = 'y';
    code[1][1][0][0] = 'z';

    while (cin >> s)
    {
        char tmp[4];
        tmp[0] = tmp[1] = tmp[2] = tmp[3] = 2;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '-')
                tmp[i] = 1;
            else if (s[i] == '.')
                tmp[i] = 0;
        }

        cout << code[tmp[0]][tmp[1]][tmp[2]][tmp[3]];
    }
}
// bug s,u
