#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ll long long

typedef struct SET
{
    ll key;
    ll value;
    struct SET *left;
    struct SET *right;
    struct SET *parent;
    unsigned char height;
} SET;

SET *createNode(ll key, ll val)
{
    SET *newNode = malloc(sizeof(SET));
    newNode->key = key;
    newNode->value = val;
    newNode->left = newNode->right = NULL;
    newNode->height = 0;

    return newNode;
}

int get_height(SET *other)
{
    return (other == NULL) ? -1 : other->height;
}

int balanceVal(SET *root)
{
    return get_height(root->right) - get_height(root->left);
}

void set_height(SET *root) //คำนวนความสูง
{
    int hl = get_height(root->left);
    int hr = get_height(root->right);

    root->height = 1 + ((hl > hr) ? hl : hr);
}

void set_left(SET *root, SET *other)
{
    root->left = other;
    if (other != NULL)
        root->left->parent = root;
}

void set_right(SET *root, SET *other)
{
    root->right = other;
    if (other != NULL)
        root->right->parent = root;
}

SET *rotate_left_child(SET *root)
{
    SET *newRoot = root->left;
    set_left(root, newRoot->right);
    set_right(newRoot, root);

    set_height(newRoot->right);
    set_height(newRoot);

    return newRoot;
}

SET *rotate_right_child(SET *root)
{
    SET *newRoot = root->right;
    set_right(root, newRoot->left);
    set_left(newRoot, root);

    set_height(newRoot->left);
    set_height(newRoot);

    return newRoot;
}

// -เอียงซ้าย +เอียงขวา
SET *rebalance(SET *root)
{
    if (root == NULL)
        return root;

    int balance = balanceVal(root);

    // Left
    if (balance == -2)
    {
        // Left-Right
        if (balanceVal(root->left) == 1)
        {
            set_left(root, rotate_right_child(root->left));
        }
        root = rotate_left_child(root);
    }
    // Right
    else if (balance == 2)
    {
        // Right-Left
        if (balanceVal(root->right) == -1)
        {
            set_right(root, rotate_left_child(root->right));
        }
        root = rotate_right_child(root);
    }

    set_height(root);
    return root;
}

SET *Insert(SET *root,ll key, ll val)
{
    if (root == NULL)
    {
        return createNode(key,val);
    }

    else if (root->key < key)
    {
        root->right = Insert(root->right,key ,val);
    }

    else if (root->key > key)
    {
        root->left = Insert(root->left,key, val);
    }

    else
    {
        root->value += val;
    }

    root = rebalance(root);
    return root;
}

int Isbalance(SET *root)
{

    if (root == NULL)
    {
        return 1;
    }

    int hl = get_height(root->left);
    int hr = get_height(root->right);

    if (abs(hl - hr) <= 1 && Isbalance(root->left) && Isbalance(root->right))
    {
        return 1;
    }

    else
        return 0;
}

ll n,ans,s,c;
SET *mp = NULL;

ll Inorder(SET *root)
{
    ll answer = 0;
    if(root == NULL)
    {
        return answer;
    }

    answer += Inorder(root->left);
    
    printf("->%lld %lld\n",root->key, root->value);
    if(root->value > 1)
    {
        mp = Insert(mp , root->key*2, root->value/2);
        root->value %= 2;
    }
    answer += root->value;
    answer += Inorder(root->right);

    return answer;
}



int main()
{
    scanf("%lld",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%lld%lld",&s,&c);   
        mp = Insert(mp,s,c);
    }

    ans = Inorder(mp);
    printf("%lld",ans);

    return 0;
}

/*
5
2 3
2 3
3 5
4 1
6 1
*/