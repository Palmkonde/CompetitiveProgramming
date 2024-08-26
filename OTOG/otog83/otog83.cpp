#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

string code;
int num[N], n;

struct Tree
{
    int val;
    Tree *left, *right;

    Tree(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};

void inSert(Tree *&a, int x)
{
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> n;

    iota(num, num + n, 1);

    int mid = (n - 1) / 2;

    cout << num[mid];

    Tree *root;
    root = new Tree(num[mid]);

    return 0;
}