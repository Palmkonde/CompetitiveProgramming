#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct SET
{
    char value[105];
    struct SET *left;
    struct SET *right;
    struct SET *parent;
    unsigned char height;
} SET;

SET *createNode(char *val)
{
    SET *newNode = malloc(sizeof(SET));
    strcpy(newNode->value, val);
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

    root->height = 1 + (hl > hr) ? hl : hr;
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
            root = rotate_right_child(root);
        }
    }

    set_height(root);
    return root;
}

int nodecnt;
SET *Insert(SET *root, char *val)
{
    if (root == NULL)
    {
        nodecnt++;
        return createNode(val);
    }

    else if (strcmp(root->value, val) < 0)
    {
        root->right = Insert(root->right, val);
    }

    else if (strcmp(root->value, val) > 0)
    {
        root->left = Insert(root->left, val);
    }

    root = rebalance(root);
    return root;
}

char last[105];

void inorder(SET *s)
{
    if (s == NULL)
    {
        return;
    }

    inorder(s->left);

    if (!((last[0] == s->value[0]) && (last[1] == s->value[1]) && (last[2] == s->value[2])))
    {
        printf("%s ", s->value);
    }

    strcpy(last, s->value);
    inorder(s->right);
}

int n;
char buff[105];

int main()
{
    scanf("%d", &n);

    SET *root = NULL;

    for (int i = 0; i < n; i++)
    {
        scanf(" %s", buff);
        root = Insert(root, buff);
    }

    printf("%d\n", nodecnt);
    memset(last, 0, sizeof(last));
    inorder(root);

    return 0;
}