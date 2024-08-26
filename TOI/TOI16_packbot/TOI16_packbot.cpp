#include <bits/stdc++.h>
using namespace std;

string code;
string postfix;
stack<char> stk;
stack<int> process;
map<char, int> mp = {
    {'3', 3},
    {'2', 2},
    {'1', 1}};

void infixtopostfix()
{
    for (int i = 0; i < code.size(); i++)
    {
        if (isalpha(code[i]))
        {
            postfix += code[i];
        }
        else
        {
            if (stk.empty())
            {
                stk.emplace(code[i]);
            }

            else if (code[i] == '[')
            {
                stk.emplace(code[i]);
            }

            else if (code[i] == ']')
            {
                while (not stk.empty() and stk.top() != '[')
                {
                    postfix += stk.top();
                    stk.pop();
                }
                stk.pop();
            }

            else
            {
                while (not stk.empty() and mp[stk.top()] >= mp[code[i]])
                {
                    postfix += stk.top();
                    stk.pop();
                }
                stk.push(code[i]);
            }
        }
    }
    while (not stk.empty())
    {
        postfix += stk.top();
        stk.pop();
    }
}

int main()
{
    cin >> code;

    infixtopostfix();

    // cout << postfix;

    for (int i = 0; i < postfix.size(); i++)
    {
        if (isalpha(postfix[i]))
        {
            process.emplace(20);
        }
        else
        {
            int b = process.top();
            process.pop();
            int a = process.top();
            process.pop();

            int tax;
            if (postfix[i] == '1')
            {
                tax = (a + b) * 0.04;
            }
            else if (postfix[i] == '2')
            {
                tax = (a + b) * 0.08;
            }
            else
            {
                tax = (a + b) * 0.16;
            }

            process.emplace((a + b + tax));
        }
    }

    cout << process.top();
    return 0;
}