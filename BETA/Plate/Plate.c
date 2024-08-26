#include <stdio.h>
#define N 10005

int id[N], a, b;
int r, n;
char c;
int ss = 0, q[N], t;

void Insert(int idx, int num)
{
    for (int i = ss; i >= idx; --i)
    {
        q[i + 1] = q[i];
    }

    q[idx] = num;
    ss++;
}

int main()
{
    scanf("%d %d", &r, &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &a, &b);
        id[b] = a;
    }

    while (1)
    {
        scanf(" %c", &c);
        if (c == 'X')
        {
            printf("0");
            return 0;
        }

        else if (c == 'E')
        {
            scanf("%d", &t);
            if (ss == 0)
            {
                Insert(0, t);
            }

            else
            {
                short inserted = 0;
                for (int i = 0; i <= ss; i++)
                {
                    if (id[q[i]] == id[t] && id[q[i + 1]] != id[t])
                    {
                        Insert(i + 1, t);
                        inserted = 1;
                        break;
                    }
                }

                if (!inserted)
                {
                    Insert(ss, t);
                }
            }
        }

        else if (c == 'D')
        {
            printf("%d\n", q[0]);

            for (int i = 0; i <= ss; i++)
            {
                q[i] = q[i + 1];
            }
            ss--;
        }
    }

    return 0;
}