#include<bits/stdc++.h>
using namespace std;

struct Tree
{
    int val;
    Tree* left;
    Tree* right;

    Tree(int a)
    {
        val = a;
        left = NULL;
        right = NULL;
    }
};

void insert(int val,Tree* &root)
{
    if(!root)
    {
        cout << "X\n";
        root = new Tree(val);
        return;
    }

    else if(val < root->val)
    {
        cout << "L ";
        insert(val,root->left);
    }
    else if(val > root->val)
    {
        cout << "R ";
        insert(val,root->right);
    }
}


int n;

int main()
{
    cin >> n;

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    Tree* root = NULL;

    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        insert(x,root);
    }

    return 0;
}