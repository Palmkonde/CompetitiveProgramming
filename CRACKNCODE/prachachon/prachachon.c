#include <stdio.h>

int q, y;
int a[18];
char buff[18];

int main()
{
    scanf("%d", &q);

    while (q--)
    {
        int res = 0;
        scanf(" %s", buff);
        for (int i = 0; i <= 12; i++)
        {
            a[i] = buff[i] - '0';
        }

        for (int i = 0; i <= 11; i++)
        {
            res += (14 - (i + 1)) * a[i];
            // printf("%d %d\n", (14 - (i + 1)), a[i]);
        }

        res = res % 11;
        y = (((11 - res) % 10) == a[12]);

        // printf("%d %d", a[12], ((11 - res) % 10));

        if (y)
        {
            printf("Y\n");
        }
        else
        {
            printf("N\n");
        }
    }

    return 0;
}