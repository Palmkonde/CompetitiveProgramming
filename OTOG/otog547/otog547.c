#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct vector
{
    char *arr;
    int mCap;
    int mSize;
}VEC;

VEC *create(int size)
{
    VEC *newVEC = (VEC*)malloc(sizeof(VEC));
    newVEC->arr = (char*)malloc(sizeof(char));
    newVEC->mSize = 0;
    newVEC->mCap = size;

    return newVEC;
}

void pB(VEC *vec, char e)
{
    vec->arr[vec->mSize++] = e;
    if(vec->mSize == vec->mCap) vec->arr = realloc(vec->arr,vec->mCap*=2 * sizeof(char));
}

int main()
{
    char a[1005],b[1005];
    while(scanf("%s%s",a,b) != EOF)
    {
        int cnt=0;
        for(int i=0;i<strlen(a);i++)
        {
            VEC *tmp = create(1);
            for(int j=0,idx = i+j;j < strlen(b) && idx < strlen(a);j++,idx++)pB(tmp,a[idx]);
            
            pB(tmp,'\0');cnt += (strcmp(tmp->arr,b) == 0);
        }
        printf("%d\n",cnt);
    }
    return 0;
}