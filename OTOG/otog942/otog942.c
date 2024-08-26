#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct SET
{
    float address;
    int value;
    struct SET *left;
    struct SET *right;
    struct SET *parent;
    unsigned char height;
} SET;

SET *createNode(float ad, int val)
{
    SET *newNode = malloc(sizeof(SET));
    newNode->address = ad;
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

SET *Insert(SET *root,float ad, int val)
{
    if (root == NULL)
    {
        return createNode(ad, val);
    }

    else if(root->address == ad)
    {
        root->value = val;
    }

    else if (root->address < ad)
    {
        root->right = Insert(root->right, ad, val);
    }

    else if (root->address > ad)
    {
        root->left = Insert(root->left, ad, val);
    }

    root = rebalance(root);
    return root;
}

int search(SET *root,float ad)
{
    //printf("root->%f\n",root->address);

    if(root->address == ad) return root->value;
    else if(root->left == NULL && root->right == NULL) return (1 << 31);
    else if(root->address < ad ) return search(root->right, ad);
    else if(root->address > ad) return search(root->left, ad);
}



void inorder(SET *s)
{
    if(s == NULL) return;
    
    inorder(s->left);
    printf("%d ",s->value);
    inorder(s->right);
}

int n,m;
char cmp[3];

int main()
{
    SET *root = NULL;

    scanf("%d%d",&n,&m);

    for(float i=-1;i<=n-2;i++) root = Insert(root,i,0);
    

    float ad;
    int val;
    while(m--)
    {   
        scanf("%s",cmp);

        if(strcmp(cmp,"pa") == 0){inorder(root);printf("\n");}
        else if(strcmp(cmp,"pi") == 0)
        {
            scanf("%f",&ad);

            if(ad < -1 || ad > n-2) {printf("error\n");continue;}
           
            val = search(root,ad);
            //printf("val->%d\n",val);
            if(val == (1 << 31)){printf("0\n");}
            else printf("%d\n",val);
        }
        else
        {
            scanf("%f%d",&ad,&val);
            if(ad < -1 || ad > n-2){ printf("error\n");continue;}
            root=Insert(root,ad,val);
        }
    }

    return 0;
}