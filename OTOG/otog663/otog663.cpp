#include<bits/stdc++.h>
using namespace std;

string temp,t2;
stack<char> oper;
stack<float> num;

string afterinfix;
stringstream ss;
map<char,int> prio = {
    {'*',2},
    {'/',2},
    {'+',1},
    {'-',1},
    {'(',-1}
};

void infixToPostfix(string temp)
{
    for(int i=0;i<temp.size();i++)
    {
        if(isalnum(temp[i]))
        {
            if(isalnum(temp[i+1]))
            {
                afterinfix += (temp[i]);
                afterinfix += temp[i+1];
                i += 1;  
            }
            else
            {
                afterinfix += temp[i];
            }
        }
        else
        {
            if(temp[i] ==  '(')
            {
                oper.push(temp[i]);
            }
            else if(temp[i] == ')')
            {
                while(oper.top() != '(')
                {
                    afterinfix += oper.top();oper.pop();
                }
                oper.pop();
            }
            else
            {
                while(!oper.empty() and prio[oper.top()] >= prio[temp[i]])
                {
                    afterinfix += oper.top();
                    oper.pop();
                }
                oper.push(temp[i]);
            }
            
        }

        afterinfix += ' ';
    }

    if(oper.size() > 0)
    {
        while(oper.size() > 0)
        {
            afterinfix += oper.top();oper.pop();
            afterinfix += ' ';
        }
    }

}

int main()
{

    cin >> temp;

    infixToPostfix(temp);
    
    afterinfix.resize(afterinfix.size()-1);
    ss << afterinfix;

    while(ss.good())
    {
        ss>>t2;

        //cout << t2 << " ";

        if(isalnum(t2[0]))
        {
            num.push(stoi(t2));
        }
        else
        {
            float b = num.top();num.pop();
            float a = num.top();num.pop();

            switch (t2[0])
            {
                case '+':
                    a+=b;
                    break;
                case '-':
                    a-=b;
                    break;
                case '*':
                    a *= b;
                    break;
                case '/':
                    a /= b;
                    break;
            }
            num.push(a);
        }
        

    }

    printf("%.1f",num.top());
    return 0;
}

/*
* /
+ -

*/