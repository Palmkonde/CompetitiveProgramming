#include<stdio.h>
#include<string.h>

typedef struct PAIR
{
    int prio;
    int idx;
    char name[20];
}pair;

char cmd[15];
int Tsize;
pair Tree[500005];

pair make_pair(char *name, int num,int idx)
{
    pair Newp;
    Newp.idx = idx;
    strcpy(Newp.name,name);
    Newp.prio = num;

    return Newp;
}

void push(char *name,int num,int idx)
{
    Tree[Tsize++] = make_pair(name,num,idx);

    int node = Tsize-1;
    pair tmp = Tree[node];

    while(node > 0)
    {
        int p = (node-1)/2;

        if(Tree[p].prio == tmp.prio && (Tree[p].idx < tmp.idx)) break;
        else if(Tree[p].prio > tmp.prio) break;

        Tree[node] = Tree[p];
        node = p;
    }
    Tree[node] = tmp;
}

void pop()
{
    Tree[0] = Tree[--Tsize];

    int node = 0;
    pair tmp = Tree[node];
    int c;
    while((c=2*node+1) < Tsize)
    {
        if(c+1 < Tsize && Tree[c+1].prio > Tree[c].prio) c++;
        else if(c+1 < Tsize && Tree[c+1].prio == Tree[c].prio && Tree[c+1].idx < Tree[c].idx) c++;

        if(tmp.prio == Tree[c].prio && (tmp.idx < Tree[c].idx)) break;
        else if(tmp.prio > Tree[c].prio) break;

        Tree[node] = Tree[c];
        node = c;
    }
    Tree[node] = tmp;
}

int main()
{
    int idx = 0;
    while(scanf("%s",cmd) && (strcmp(cmd,"Exit") != 0))
    {
        if(strcmp(cmd,"New") == 0) 
        {
            char name[15];
            int num;
            scanf("%s%d",name,&num);
            push(name,num,idx++);
        }
        if(strcmp(cmd,"Call") == 0)
        {
            printf("%s\n",Tree[0].name);
            pop();
        }
    }
    return 0;
}