#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int n,q;
char num[1005],ans[1005];

typedef struct vector
{
    char *arr;
    int mCap;
    int mSize;
}Vec;

Vec *create(int size)
{
    Vec *newVec = (Vec*)malloc(sizeof(Vec));
    newVec->mCap = size;
    newVec->mSize = 0;
    newVec->arr = (char *)malloc(sizeof(char) * size);

    return newVec; 
}

void pb(Vec *v,char e)
{
    v->arr[v->mSize++] = e;
    if(v->mSize == v->mCap) v->arr = realloc(v->arr,v->mCap*=2 * sizeof(char));
}

void convertTo(char *num,int base,int base2)
{
    int ten = 0;
    for(int i=strlen(num)-1, idx = 1;i>=0;i--,idx*=base)     
        ten += (num[i]-'0')*idx;
    
    Vec *arr = create(1005);
    while(ten > 0)
    {
        pb(arr, ten%base2 + '0');
        ten /= base2;
    }
    for(int i=arr->mSize-1;i>=0;i--) printf("%c",arr->arr[i]);
}

int main()
{
    scanf("%d%d%s",&n,&q,num);

    convertTo(num,n,q);
    return 0;
}