#include <stdio.h>
#include <stdlib.h>
#define MAX(x, y) (x > y) ? x : y

typedef struct SET
{
    int value;
    struct SET *left;
    struct SET *right;
    struct SET *parent;
    unsigned char height;
} SET;

SET *createSET(int val)
{
    SET *newSET = (SET *)malloc(sizeof(SET));
    newSET->value = val;
    newSET->left = newSET->right = newSET->parent = NULL;
    newSET->height = 1;

    return newSET;
}

int get_height(SET *root)
{
    return (root == NULL) ? -1 : root->height;
}

int balanceVal(SET *root)
{
    return get_height(root->right) - get_height(root->left);
}

void set_height(SET *root)
{
    int hl = get_height(root->left);
    int hr = get_height(root->right);

    return 1 + (hl > hr) ? hl : hr;
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
    SET *newNode = root->left;
    set_left(root, newNode->right);
    set_right(newNode, root);

    set_height(newNode->right);
    set_height(newNode);

    return newNode;
}

SET *rotate_right_child(SET *root)
{
    SET *newNode = root->right;
    set_right(root, newNode->left);
    set_left(newNode, root);

    set_height(newNode->right);
    set_height(newNode);

    return newNode;
}

SET *rebalance(SET *root)
{
    if (root == NULL)
        return root;

    int balance = balanceVal(root);

    if (balance == -2)
    {
        if (balanceVal(root->left) == -1)
        {
            set_left(root, rotate_right_child(root->left));
        }
        root = rotate_left_child(root);
    }

    else if (balance == 2)
    {
        if (balanceVal(root->right) == 1)
        {
            set_right(root, rotate_left_child(root->right));
        }
        root = rotate_right_child(root);
    }

    set_height(root);
    return root;
}

int nodeCnt;

SET *Insert(SET *root, int val)
{
    if (root == NULL)
    {
        nodeCnt++;
        return createSET(val);
    }

    if (root->value > val)
    {
        root->left = Insert(root->left, val);
    }

    else if (root->value < val)
    {
        root->right = Insert(root->right, val);
    }

    root = rebalance(root);
    return root;
}

int n, k;

int main()
{
    SET *root = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &k);
        root = Insert(root, k);
    }

    printf("%d", nodeCnt);

    return 0;
}